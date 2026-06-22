#include "template/template.hpp"

// #define MULTI_TESTCASE

void testcase() {
  int n = input();
  vector<int> h(n), l(n);
  rep (i, n) {
    h[i] = input();
    l[i] = input();
  }

  vector<int> mx(n);
  mx[n - 1] = h[n - 1];
  rrep (i, n - 1) mx[i] = max(mx[i + 1], h[i]);

  int q = input();
  rep (_, q) {
    int t = input();
    int i = upper_bound(l.begin(), l.end(), t) - l.begin();
    output(mx[i]);
  }
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
    std::clog << "\033[36mCase #" << i + 1 << "\033[0m" << std::endl;
    testcase();
  }
#endif
  return 0;
}
