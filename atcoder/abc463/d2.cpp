#include "template/template.hpp"

#include "typical/interval_scheduling.hpp"

// #define MULTI_TESTCASE

void testcase() {
  int n = input();
  int k = input();
  vector<pair<lint, lint>> I(n);
  rep (i, n) {
    I[i].first = input();
    I[i].second = input();
  }

  lint lo = 0, hi = 2e9;
  while (hi - lo > 1) {
    lint mi = (lo + hi) / 2;
    auto J = I;
    for (auto& [l, r]: J) r += mi;
    (interval_scheduling(J).size() >= k ? lo : hi) = mi;
  }
  output(lo == 0 ? -1 : lo);
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
