// Copy this file to datasets/cpp-<family>.cpp and replace the examples with
// reviewed code. Keep globals used by a function in the same file so the
// native analyzer can resolve them.

int batchTemplateLinear(int n) {
  int answer = 0;
  for (int i = 0; i < n; ++i) answer += i;
  return answer;
}
