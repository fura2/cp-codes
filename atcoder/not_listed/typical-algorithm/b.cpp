#include "template/template.hpp"

#include "typical/interval_scheduling.hpp"

// #define MULTI_TESTCASE

void testcase() {
  int n = input();
  vector<pair<int, int>> I(n);
  rep (i, n) {
    I[i].first = input();
    I[i].second = input();
  }
  output(interval_scheduling(I).size());
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
