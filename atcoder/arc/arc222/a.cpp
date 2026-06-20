#include "template/template.hpp"

#define MULTI_TESTCASE

void testcase() {
  int n = input();
  int m = input();
  vector<int> l(m), r(m);
  rep (i, m) {
    l[i] = input();
    r[i] = input();
    l[i]--;
  }

  int mx = 0;
  rep (i, m) chmax(mx, r[i] - l[i]);

  vector<int> ans(n);
  rep (i, n) ans[i] = i % mx + 1;
  output(ans);
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
#ifdef LOCAL
    std::cerr << std::format("\033[36mCase #{}\033[0m\n", i + 1);
#endif
    testcase();
  }
#endif
  return 0;
}
