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

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> l(q), r(q);
  rep (i, q) cin >> l[i] >> r[i], l[i]--;

  vector<int> X = {0, n};
  rep (i, q) {
    X.emplace_back(l[i]);
    X.emplace_back(r[i]);
  }
  sort(all(X));
  X.erase(unique(all(X)), X.end());
  int m = X.size();

  vector<int> a(q), b(q);
  rep (i, q) {
    a[i] = lower_bound(all(X), l[i]) - X.begin();
    b[i] = lower_bound(all(X), r[i]) - X.begin();
  }

  vector<int> color(m);
  vector<int> nxt(m); // 次の白マスの位置
  rep (x, m) nxt[x] = x + 1;

  int ans = n;
  rep (i, q) {
    int x = a[i];
    vector<int> his;
    while (x < b[i]) {
      if (color[x] == 0) {
        color[x] = 1;
        ans -= X[x + 1] - X[x];
      }
      his.emplace_back(x);
      x = nxt[x];
    }

    // path compression
    for (auto y: his) nxt[y] = x;

    cout << ans << "\n";
  }

  return 0;
}
