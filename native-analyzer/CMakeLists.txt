cmake_minimum_required(VERSION 3.24)
project(project_x_native_analyzer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Clang_DIR and LLVM_DIR are supplied by the Project X bootstrap after it builds
# the pinned LLVM development dependency. Do not fall back to a random system
# Clang: its headers and libraries must match exactly.
find_package(LLVM CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)

add_executable(project-x-native-analyzer src/main.cpp)

target_include_directories(project-x-native-analyzer PRIVATE
  ${LLVM_INCLUDE_DIRS}
  ${CLANG_INCLUDE_DIRS}
)
target_compile_definitions(project-x-native-analyzer PRIVATE ${LLVM_DEFINITIONS})

target_link_libraries(project-x-native-analyzer PRIVATE
  clangTooling
  clangASTMatchers
  clangFrontend
  clangSerialization
  clangParse
  clangSema
  clangAnalysis
  clangEdit
  clangAST
  clangLex
  clangBasic
)
