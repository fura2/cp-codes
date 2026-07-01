#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  int n = input<int>();
  int mod = input<int>();

  vector<vector<lint>> A(11);
  rep (i, n) {
    auto s = input<string>();
    A[s.size()].emplace_back(stoll(s) % mod);
  }
  rep (i, 11) ranges::sort(A[i]);

  lint ten[11] = {1};
  rep (i, 10) ten[i + 1] = ten[i] * 10 % mod;

  lint ans = 0;
  rep (i, 11)
    for (lint x: A[i])
      rep (j, 11)
        ans += ranges::equal_range(A[j], (mod - x * ten[j] % mod) % mod).size();
  output(ans);
}
