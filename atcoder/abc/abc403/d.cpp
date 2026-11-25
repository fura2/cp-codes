#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "string/run_length_encoding.hpp"
#include "template/main.hpp"

// 連続する数のペアが存在しないように最小個数の要素を消す
int f(vector<int> a) {
  if (a.empty()) return 0;

  ranges::sort(a);

  auto rle = run_length_encoding(a);

  int n = rle.size();
  vector dp(n, vector(2, INF));  // dp[*][0] = 消す, dp[*][1] = 残す
  dp[0][0] = rle[0].second;
  dp[0][1] = 0;
  rep (i, 1, n) {
    int v = min(dp[i - 1][0], dp[i - 1][1]);
    if (rle[i - 1].first + 1 < rle[i].first) {
      dp[i][0] = v + rle[i].second;
      dp[i][1] = v;
    }
    else {
      dp[i][0] = v + rle[i].second;
      dp[i][1] = dp[i - 1][0];
    }
  }
  return min(dp[n - 1][0], dp[n - 1][1]);
}

void testcase() {
  auto n = input<int>(), d = input<int>();
  auto a = input<vector<int>>(n);

  if (d == 0) {
    map<int, int> h;
    rep (i, n) ++h[a[i]];
    int ans = 0;
    for (auto [k, v]: h) ans += v - 1;
    output(ans);
    return;
  }

  vector h(d, vector<int>());
  rep (i, n) {
    h[a[i] % d].emplace_back(a[i] / d);
  }
  int ans = 0;
  rep (x, d) ans += f(h[x]);
  output(ans);
}
