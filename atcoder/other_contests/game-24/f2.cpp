#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  unordered_map<string, bool> memo;  // true: 後手必勝
  auto dfs = [&](auto&& dfs, string s) {
    if (memo.contains(s)) return memo[s];

    if (s.empty()) return memo[s] = true;

    int n = s.size();
    rep (i, n - 1) {
      if (s[i] != s[i + 1] && dfs(dfs, s.substr(0, i) + s.substr(i + 2)))
        return memo[s] = false;
    }
    return memo[s] = true;
  };

  alicebob(!dfs(dfs, s));
}
