#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

// clang-format off
#define impl_overload4(a, b, c, d, e, ...) e

#define impl_rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define impl_rep3(i, a, b) impl_rep4(i, a, b, 1)
#define impl_rep2(i, n) impl_rep3(i, 0, n)
#define impl_rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) impl_overload4(__VA_ARGS__, impl_rep4, impl_rep3, impl_rep2, impl_rep1)(__VA_ARGS__)

#define impl_rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define impl_rrep3(i, a, b) impl_rrep4(i, a, b, 1)
#define impl_rrep2(i, n) impl_rrep3(i, 0, n)
#define rrep(...) impl_overload4(__VA_ARGS__, impl_rrep4, impl_rrep3, impl_rrep2)(__VA_ARGS__)

#define all(v) std::begin(v), std::end(v)

template<typename T>
constexpr int bit(T x, unsigned int k) { return (x >> k) & 1; }

template<typename T>
constexpr bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }
template<typename T>
constexpr bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }

constexpr void yesno(bool b) { std::cout << (b ? "Yes" : "No") << "\n"; }
constexpr void yes() { yesno(true); }
constexpr void no() { yesno(false); }

struct Setup {
  Setup() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);
  }
} setup;
// clang-format on

#ifdef LOCAL
#include "template_local.hpp"
#else
#define show(...) ((void)0)
#endif

using lint = long long;

using namespace std;

#endif // TEMPLATE_HPP

constexpr int INF = 1 << 29;
constexpr int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> B(h);
  rep (i, h) cin >> B[i];

  bool cused[128] = {};
  vector dist(h, vector(w, INF));
  dist[0][0] = 0;
  queue<pair<int, int>> Q;
  Q.emplace(0, 0);
  while (!Q.empty()) {
    auto [x, y] = Q.front();
    Q.pop();
    rep (k, 4) {
      int x2 = x + dx[k], y2 = y + dy[k];
      if (0 <= x2 && x2 < h && 0 <= y2 && y2 < w && B[x2][y2] != '#'
          && dist[x2][y2] == INF) {
        dist[x2][y2] = dist[x][y] + 1;
        Q.emplace(x2, y2);
      }
      if (islower(B[x][y]) && !cused[B[x][y]]) {
        cused[B[x][y]] = true;
        rep (i, h)
          rep (j, w)
            if (B[i][j] == B[x][y] && dist[i][j] == INF) {
              dist[i][j] = dist[x][y] + 1;
              Q.emplace(i, j);
            }
      }
    }
  }
  cout << (dist[h - 1][w - 1] == INF ? -1 : dist[h - 1][w - 1]) << endl;

  return 0;
}
