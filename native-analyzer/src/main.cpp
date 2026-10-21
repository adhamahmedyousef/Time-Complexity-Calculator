#include <clang/AST/ASTConsumer.h>
#include <clang/AST/ASTContext.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Analysis/CFG.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/Tooling.h>

#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <string>
#include <vector>

namespace {

struct AstSummary {
  unsigned functions = 0;
  unsigned forLoops = 0;
  unsigned whileLoops = 0;
  unsigned doLoops = 0;
  unsigned rangeForLoops = 0;
  unsigned calls = 0;
  struct FunctionFact {
    std::string name;
    unsigned cfgBlocks = 0;
    unsigned directCalls = 0;
    unsigned selfRecursiveCalls = 0;
    unsigned forLoops = 0;
    unsigned whileLoops = 0;
    unsigned doLoops = 0;
    unsigned rangeForLoops = 0;
    std::vector<std::string> directCallees;
  };
  std::vector<FunctionFact> functionFacts;
};

class SummaryVisitor : public clang::RecursiveASTVisitor<SummaryVisitor> {
 public:
  SummaryVisitor(AstSummary &summary, clang::ASTContext &context)
      : summary_(summary), context_(context) {}

  bool VisitFunctionDecl(clang::FunctionDecl *declaration) {
    if (!declaration->doesThisDeclarationHaveABody() ||
        !declaration->isThisDeclarationADefinition() ||
        !context_.getSourceManager().isWrittenInMainFile(declaration->getLocation()))
      return true;

    ++summary_.functions;
    AstSummary::FunctionFact fact;
    fact.name = declaration->getQualifiedNameAsString();
    struct CallVisitor : clang::RecursiveASTVisitor<CallVisitor> {
      explicit CallVisitor(const clang::FunctionDecl *owner,
                           AstSummary::FunctionFact &fact)
          : owner(owner), fact(fact) {}
      bool VisitCallExpr(clang::CallExpr *call) {
        ++fact.directCalls;
        if (const auto *callee = call->getDirectCallee()) {
          if (callee == owner) ++fact.selfRecursiveCalls;
          callees.insert(callee->getQualifiedNameAsString());
        }
        return true;
      }
      const clang::FunctionDecl *owner;
      AstSummary::FunctionFact &fact;
      std::set<std::string> callees;
    } calls(declaration, fact);
    calls.TraverseStmt(declaration->getBody());
    fact.directCallees.assign(calls.callees.begin(), calls.callees.end());

    struct LoopVisitor : clang::RecursiveASTVisitor<LoopVisitor> {
      explicit LoopVisitor(AstSummary::FunctionFact &fact) : fact(fact) {}
      bool VisitForStmt(clang::ForStmt *) { ++fact.forLoops; return true; }
      bool VisitWhileStmt(clang::WhileStmt *) { ++fact.whileLoops; return true; }
      bool VisitDoStmt(clang::DoStmt *) { ++fact.doLoops; return true; }
      bool VisitCXXForRangeStmt(clang::CXXForRangeStmt *) { ++fact.rangeForLoops; return true; }
      AstSummary::FunctionFact &fact;
    } loops(fact);
    loops.TraverseStmt(declaration->getBody());

    clang::CFG::BuildOptions options;
    std::unique_ptr<clang::CFG> cfg = clang::CFG::buildCFG(
        declaration, declaration->getBody(), &context_, options);
    if (cfg) fact.cfgBlocks = cfg->size();
    summary_.functionFacts.push_back(std::move(fact));
    return true;
  }

  bool VisitForStmt(clang::ForStmt *) {
    ++summary_.forLoops;
    return true;
  }

  bool VisitWhileStmt(clang::WhileStmt *) {
    ++summary_.whileLoops;
    return true;
  }

  bool VisitDoStmt(clang::DoStmt *) {
    ++summary_.doLoops;
    return true;
  }

  bool VisitCXXForRangeStmt(clang::CXXForRangeStmt *) {
    ++summary_.rangeForLoops;
    return true;
  }

  bool VisitCallExpr(clang::CallExpr *call) {
    if (context_.getSourceManager().isWrittenInMainFile(call->getExprLoc()))
      ++summary_.calls;
    return true;
  }

 private:
  AstSummary &summary_;
  clang::ASTContext &context_;
};

class SummaryConsumer : public clang::ASTConsumer {
 public:
  explicit SummaryConsumer(AstSummary &summary) : summary_(summary) {}

  void HandleTranslationUnit(clang::ASTContext &context) override {
    visitor_ = std::make_unique<SummaryVisitor>(summary_, context);
    visitor_->TraverseDecl(context.getTranslationUnitDecl());
  }

 private:
  AstSummary &summary_;
  std::unique_ptr<SummaryVisitor> visitor_;
};

class SummaryAction : public clang::ASTFrontendAction {
 public:
  explicit SummaryAction(AstSummary &summary) : summary_(summary) {}

  std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
      clang::CompilerInstance &, llvm::StringRef) override {
    return std::make_unique<SummaryConsumer>(summary_);
  }

 private:
  AstSummary &summary_;
};

}  // namespace

static void printJsonString(const std::string &value) {
  std::cout << '"';
  for (const char character : value) {
    if (character == '\\' || character == '"') std::cout << '\\';
    if (character == '\n') std::cout << "\\n";
    else if (character == '\r') std::cout << "\\r";
    else if (character == '\t') std::cout << "\\t";
    else if (character != '\n') std::cout << character;
  }
  std::cout << '"';
}

int main() {
  const std::string source(std::istreambuf_iterator<char>(std::cin), {});
  if (source.empty()) {
    std::cout << R"({"parsed":false,"reason":"No C++ source was provided."})" << '\n';
    return 2;
  }

  AstSummary summary;
  const bool parsed = clang::tooling::runToolOnCodeWithArgs(
      std::make_unique<SummaryAction>(summary), source, {"-std=c++17"}, "selection.cpp");

  std::cout << "{\"parsed\":" << (parsed ? "true" : "false")
            << ",\"functions\":" << summary.functions
            << ",\"forLoops\":" << summary.forLoops
            << ",\"whileLoops\":" << summary.whileLoops
            << ",\"doLoops\":" << summary.doLoops
            << ",\"rangeForLoops\":" << summary.rangeForLoops
            << ",\"calls\":" << summary.calls
            << ",\"functionFacts\":[";
  for (std::size_t index = 0; index < summary.functionFacts.size(); ++index) {
    const auto &fact = summary.functionFacts[index];
    if (index) std::cout << ',';
    std::cout << "{\"name\":";
    printJsonString(fact.name);
    std::cout << ",\"cfgBlocks\":" << fact.cfgBlocks
              << ",\"directCalls\":" << fact.directCalls
              << ",\"selfRecursiveCalls\":" << fact.selfRecursiveCalls
              << ",\"forLoops\":" << fact.forLoops
              << ",\"whileLoops\":" << fact.whileLoops
              << ",\"doLoops\":" << fact.doLoops
              << ",\"rangeForLoops\":" << fact.rangeForLoops
              << ",\"directCallees\":[";
    for (std::size_t calleeIndex = 0; calleeIndex < fact.directCallees.size(); ++calleeIndex) {
      if (calleeIndex) std::cout << ',';
      printJsonString(fact.directCallees[calleeIndex]);
    }
    std::cout << "]"
              << '}';
  }
  std::cout << "]}" << '\n';
  return parsed ? 0 : 1;
}
