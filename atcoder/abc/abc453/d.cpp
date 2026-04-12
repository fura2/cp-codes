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
    std::cout << std::fixed << std::setprecision(11);
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

int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> B(h);
  rep (i, h) cin >> B[i];

  int sx, sy, gx, gy;
  rep (i, h) {
    rep (j, w) {
      if (B[i][j] == 'S') {
        sx = i;
        sy = j;
        B[i][j] = '.';
      }
      else if (B[i][j] == 'G') {
        gx = i;
        gy = j;
        B[i][j] = '.';
      }
    }
  }

  static bool vis[1000][1000][4];
  static int pre[1000][1000][4];
  queue<tuple<int, int, int>> Q;
  rep (k, 4) {
    vis[sx][sy][k] = true;
    Q.emplace(sx, sy, k);
  }
  while (!Q.empty()) {
    auto [x, y, k] = Q.front();
    Q.pop();

    if (x == gx && y == gy) {
      yes();
      vector<int> ds;
      while (!(x == sx && y == sy)) {
        ds.emplace_back(k);
        int tmp = k;
        k = pre[x][y][k];
        x -= dx[tmp % 4];
        y -= dy[tmp % 4];
      }
      reverse(all(ds));
      for (auto k: ds) {
        cout << "RULD"[k];
      }
      cout << endl;
      return 0;
    }

    rep (k2, 4) {
      int x2 = x + dx[k2], y2 = y + dy[k2];
      if (!(0 <= x2 && x2 < h && 0 <= y2 && y2 < w)) continue;
      if (vis[x2][y2][k2] || B[x2][y2] == '#' || (B[x][y] == 'o' && k != k2)
          || (B[x][y] == 'x' && k == k2))
        continue;
      vis[x2][y2][k2] = true;
      pre[x2][y2][k2] = k;
      Q.emplace(x2, y2, k2);
    }
  }

  no();

  return 0;
}
