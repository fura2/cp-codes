#include "template/template.hpp"

// #define MULTI_TESTCASE

void testcase() {
  int n = input();
  int d = input();
  vector<int> s(n), t(n);
  rep (i, n) {
    s[i] = input();
    t[i] = input();
    s[i]--;
  }

  int m = 1000000;
  vector<lint> C(m + 1);
  rep (i, n) {
    if (t[i] - s[i] >= d) {
      C[s[i]]++;
      C[t[i] - d]--;
    }
  }
  rep (k, m) {
    C[k + 1] += C[k];
  }

  lint ans = 0;
  rep (k, m) {
    ans += C[k] * (C[k] - 1) / 2;
  }
  output(ans);
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
    std::clog << "\033[32mCase #" << i + 1 << "\033[0m" << std::endl;
    testcase();
  }
#endif
  return 0;
}
