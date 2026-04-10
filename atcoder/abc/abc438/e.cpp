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

template<class M>
M pow(M f, long long k) {
  M res;
  for (; k > 0; k >>= 1) {
    if (k & 1) res = res * f;
    f = f * f;
  }
  return res;
}

int n;
vector<int> a;

struct F {
  vector<int> to;
  vector<lint> val;
  F() {
    to.resize(n);
    iota(all(to), 0);
    val.assign(n, 0);
  }
  F(const vector<int>& to, const vector<lint>& val): to(to), val(val) {}
  F operator*(const auto& f) const {
    vector<int> to2(n);
    vector<lint> val2(n);
    rep (i, n) {
      to2[i] = to[f.to[i]];
      val2[i] = val[f.to[i]] + f.val[i];
    }
    return {to2, val2};
  }
};

int main() {
  int q;
  cin >> n >> q;
  a.resize(n);
  rep (i, n) cin >> a[i], a[i]--;
  vector<int> t(q), b(q);
  rep (i, q) cin >> t[i] >> b[i], b[i]--;

  vector<lint> val(n);
  iota(all(val), 1);
  F f{a, val};

  vector<F> pw(30);
  pw[0] = f;
  rep (i, 29) pw[i + 1] = pw[i] * pw[i];

  rep (i, q) {
    int k = t[i];
    int pos = b[i];
    lint val = 0;
    rep (j, 30) {
      if (bit(k, j)) {
        val += pw[j].val[pos];
        pos = pw[j].to[pos];
      }
    }
    cout << val << "\n";
    // cout << pow(f, t[i]).val[b[i]] << "\n";
  }

  return 0;
}
