#include "template/template.hpp"

// #define MULTI_TESTCASE

void testcase() {
  int n = input();
  vector<vector<int>> ans(n);
  rep (i, n) {
    int k = input();
    rep (j, k) {
      int v = input();
      v--;
      ans[v].emplace_back(i);
    }
  }
  rep (i, n) {
    cout << ans[i].size();
    for (auto v: ans[i]) cout << " " << v + 1;
    cout << "\n";
  }
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
