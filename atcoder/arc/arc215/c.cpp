#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define impl_overload4(a, b, c, d, e, ...) e
#define impl_overload5(a, b, c, d, e, f, ...) f
#define impl_overload6(a, b, c, d, e, f, g, ...) g
#define impl_overload7(a, b, c, d, e, f, g, h, ...) h

// clang-format off
#define impl_rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define impl_rep3(i, a, b) impl_rep4(i, a, b, 1)
#define impl_rep2(i, n) impl_rep3(i, 0, n)
#define impl_rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) impl_overload4(__VA_ARGS__, impl_rep4, impl_rep3, impl_rep2, impl_rep1)(__VA_ARGS__)

#define impl_rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define impl_rrep3(i, a, b) impl_rrep4(i, a, b, 1)
#define impl_rrep2(i, n) impl_rrep3(i, 0, n)
#define rrep(...) impl_overload4(__VA_ARGS__, impl_rrep4, impl_rrep3, impl_rrep2)(__VA_ARGS__)
// clang-format on

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)

template<typename T>
constexpr int bit(T x, unsigned int k) {
  return (x >> k) & 1;
}

template<typename T>
constexpr bool chmax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
template<typename T>
constexpr bool chmin(T& a, const T& b) {
  return a > b ? a = b, true : false;
}

void yesno(bool b) {
  std::cout << (b ? "Yes" : "No") << "\n";
}
void yes() {
  yesno(true);
}
void no() {
  yesno(false);
}

struct Setup {
  Setup() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(11);
  }
} setup;

#ifdef LOCAL
#include "template_local.hpp"
#else
#define show(...) ((void)0)
#endif

using uint = unsigned int;
using lint = long long;
using ulint = unsigned long long;

using namespace std;

#endif // TEMPLATE_HPP

struct triple {
  int x, y, z;
};

void solve() {
  int n;
  cin >> n;
  vector<triple> a(n);
  rep (i, n) cin >> a[i].x >> a[i].y >> a[i].z;

  vector<int> px(n), py(n), pz(n);
  iota(all(px), 0);
  sort(all(px), [&](int i, int j) { return a[i].x > a[j].x; });
  iota(all(py), 0);
  sort(all(py), [&](int i, int j) { return a[i].y > a[j].y; });
  iota(all(pz), 0);
  sort(all(pz), [&](int i, int j) { return a[i].z > a[j].z; });

  int x_min = min({a[px[0]].x, a[py[0]].x, a[pz[0]].x});
  int y_min = min({a[px[0]].y, a[py[0]].y, a[pz[0]].y});
  int z_min = min({a[px[0]].z, a[py[0]].z, a[pz[0]].z});
  int ix = 0, iy = 0, iz = 0;
  while (true) {
    bool changed = false;
    auto f = [&](int i) {
      if (a[i].x >= x_min || a[i].y >= y_min || a[i].z >= z_min) {
        chmin(x_min, a[i].x);
        chmin(y_min, a[i].y);
        chmin(z_min, a[i].z);
        return true;
      }
      return false;
    };
    if (ix < n && f(px[ix])) ix++, changed = true;
    if (iy < n && f(py[iy])) iy++, changed = true;
    if (iz < n && f(pz[iz])) iz++, changed = true;
    if (!changed) break;
  }

  int ans = 0;
  rep (i, n) {
    if (a[i].x >= x_min || a[i].y >= y_min || a[i].z >= z_min) ans++;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  rep (_, t) solve();
  return 0;
}
