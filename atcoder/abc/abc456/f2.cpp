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

template<typename M>
class FoldableQueue {
 public:
  FoldableQueue(): cum_front{M{}} {}
  void push(const M& m) {
    back.emplace_back(m);
    cum_back *= m;
  }
  M pop() {
    if (front.empty()) {
      while (!back.empty()) {
        front.emplace_back(move(back.back()));
        cum_front.emplace_back(front.back() * cum_front.back());
        back.pop_back();
      }
      cum_back = M{};
    }
    auto res = move(front.back());
    front.pop_back();
    cum_front.pop_back();
    return res;
  }
  M fold() const {
    return cum_front.back() * cum_back;
  }
  int size() const {
    return front.size() + back.size();
  }

 private:
  vector<M> front, back;
  vector<M> cum_front;
  M cum_back;
};

constexpr lint INF = 1LL << 61;

struct M {
  array<array<lint, 2>, 2> a;
  M() {
    a = {
        {{0, INF}, {INF, 0}}
    };
  }
  M operator*(const M& m) const {
    M res;
    res.a = {
        {{INF, INF}, {INF, INF}}
    };
    rep (i, 2) {
      rep (j, 2) {
        rep (k, 2) {
          chmin(res.a[i][j], a[i][k] + m.a[k][j]);
        }
      }
    }
    return res;
  }
  M& operator*=(const M& m) {
    return *this = *this * m;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<lint> a(n);
  rep (i, n) cin >> a[i];

  vector<M> b(n);
  rep (i, n) {
    b[i].a = {
        {{a[i], a[i]}, {0, INF}}
    };
  }

  lint ans = INF;
  FoldableQueue<M> Q;
  rep (i, n) {
    Q.push(b[i]);
    while (Q.size() > k) Q.pop();
    if (Q.size() == k) {
      auto x = Q.fold();
      chmin(ans, x.a[0][1]);
      if (i < n - 1) {
        chmin(ans, (x * b[i + 1]).a[0][1]);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  rep (_, t) solve();
  return 0;
}
