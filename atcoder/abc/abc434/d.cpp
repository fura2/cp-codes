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
  int n;
  cin >> n;
  int m = 2000;
  vector B(m + 1, vector(m + 1, 0));
  vector<int> u(n), d(n), l(n), r(n);
  rep (i, n) {
    cin >> u[i] >> d[i] >> l[i] >> r[i];
    u[i]--, l[i]--;
    B[u[i]][l[i]]++;
    B[u[i]][r[i]]--;
    B[d[i]][l[i]]--;
    B[d[i]][r[i]]++;
  }
  rep (i, m + 1)
    rep (j, m) B[i][j + 1] += B[i][j];
  rep (j, m + 1)
    rep (i, m) B[i + 1][j] += B[i][j];

  lint nz = 0;
  vector cum(m + 1, vector(m + 1, 0LL));
  rep (i, m) {
    rep (j, m) {
      if (B[i][j] == 0) nz++;
      if (B[i][j] == 1) cum[i + 1][j + 1] = 1;
    }
  }
  rep (i, m) {
    rep (j, m) {
      cum[i + 1][j + 1] += cum[i + 1][j] + cum[i][j + 1] - cum[i][j];
    }
  }

  rep (i, n) {
    cout << nz + cum[d[i]][r[i]] - cum[d[i]][l[i]] - cum[u[i]][r[i]]
                + cum[u[i]][l[i]]
         << "\n";
  }

  return 0;
}
