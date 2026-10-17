#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto s = input<vector<string>>(n);
  vector<int> ans(n);
  rep (_, m) {
    auto t = input<string>();
    int i;
    for (i = 0; i < n; i++)
      if (s[i] == t) break;
    if (i < n) {
      ans[i]++;
      continue;
    }
    vector<int> C;
    for (i = 0; i < n; i++) {
      if (s[i].size() != t.size()) continue;
      int cnt = 0;
      rep (j, s[i].size())
        if (s[i][j] != t[j]) cnt++;
      if (cnt == 1) C.emplace_back(i);
    }
    if (C.size() == 1) ans[C[0]]++;
  }
  output(ans);
}
