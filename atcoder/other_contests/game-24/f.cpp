#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  unordered_map<int, bool> memo;  // true: 後手必勝
  auto dfs = [&](auto&& dfs, int S) {
    if (memo.contains(S)) return memo[S];

    if (S == 0) return memo[S] = true;

    int T = S;
    int i = countr_zero<uint>(T);
    T &= ~(1 << i);
    while (true) {
      int j = countr_zero<uint>(T);
      if (j >= n) break;
      T &= ~(1 << j);
      if (s[i] != s[j] && dfs(dfs, S & ~(1 << i) & ~(1 << j))) {
        return memo[S] = false;
      }
      i = j;
    }
    return memo[S] = true;
  };

  alicebob(!dfs(dfs, (1 << n) - 1));
}
