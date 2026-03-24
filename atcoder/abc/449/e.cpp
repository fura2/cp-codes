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

template<class G>
class Fenwick_tree {
  vector<G> a;

 public:
  Fenwick_tree(int n = 0) {
    build(n);
  }
  Fenwick_tree(const vector<G>& a) {
    build(a);
  }
  void build(int n) {
    a.assign(n, G{});
  }
  void build(const vector<G>& a) {
    this->a = a;
    for (int i = 1; i <= a.size(); i++)
      if (i + (i & -i) <= a.size()) (this->a)[i + (i & -i) - 1] += (this->a)[i - 1];
  }
  void add(int i, const G& val) {
    for (i++; i <= a.size(); i += i & -i) a[i - 1] += val;
  }
  G sum(int l, int r) const {
    if (l == 0) {
      G res{};
      for (; r > 0; r -= r & -r) res += a[r - 1];
      return res;
    }
    return sum(0, r) - sum(0, l);
  }
  int lower_bound(G val) const {
    if (!(G{} < val)) return 0;
    int x = 0, k;
    for (k = 1; k <= a.size(); k <<= 1);
    for (k >>= 1; k > 0; k >>= 1)
      if (x + k <= a.size() && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
    return x;
  }
  int upper_bound(G val) const {
    if (val < G{}) return 0;
    int x = 0, k;
    for (k = 1; k <= a.size(); k <<= 1);
    for (k >>= 1; k > 0; k >>= 1)
      if (x + k <= a.size() && !(val < a[x + k - 1])) val -= a[x + k - 1], x += k;
    return x;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep (i, n) cin >> a[i], a[i]--;
  int q;
  cin >> q;
  vector<lint> x(q);
  rep (i, q) cin >> x[i], x[i]--;

  vector<int> hist(m + 1);
  rep (i, n) hist[a[i]]++;

  vector<vector<int>> f(n + 1);
  rep (v, m) {
    f[hist[v]].emplace_back(v);
  }

  vector<int> p(q);
  iota(all(p), 0);
  sort(all(p), [&](int i, int j) { return x[i] < x[j]; });

  vector<int> ans(q, -1);
  int idx = 0;
  while (idx < q && x[p[idx]] < n) {
    ans[p[idx]] = a[x[p[idx]]];
    idx++;
  }

  lint len = n;
  lint cnt = 0;
  Fenwick_tree<int> F(m);
  rep (k, n + 1) { // 現在の A にちょうど k 個含まれている数の処理
    for (int v: f[k]) { // A[0..n) にちょうど k 個含まれている数を F に追加
      F.add(v, 1);
      cnt++;
    }
    while (idx < q && x[p[idx]] < len + cnt) {
      ans[p[idx]] = F.lower_bound(x[p[idx]] - len + 1);
      idx++;
    }
    len += cnt; // まとめて A の末尾に追加
  }

  while (idx < q) {
    ans[p[idx]] = (x[p[idx]] - len) % m;
    idx++;
  }

  rep (i, q) cout << ans[i] + 1 << "\n";

  return 0;
}
