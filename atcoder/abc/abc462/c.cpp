#include "template/template.hpp"

// #define MULTI_TESTCASE

void testcase() {
  int n = input();
  vector<pair<int, int>> p(n);
  rep (i, n) {
    cin >> p[i].first >> p[i].second;
  }
  ranges::sort(p);

  int ans = 0, ymin = n + 1;
  rep (i, n) {
    if (p[i].second < ymin) {
      ans++;
      ymin = p[i].second;
    }
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
