// solution based on 公式解説放送

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

constexpr lint INF = 1LL << 61;

struct Elem {
  lint sum;
  int kind;
};

using Top2 = pair<Elem, Elem>; // kind の値が異なる top 2

void update(Top2& t, const Elem& e) {
  if (e.kind == t.first.kind) {
    if (t.first.sum < e.sum) {
      t.first = e;
    }
  }
  else {
    if (t.first.sum < e.sum) {
      t.second = t.first;
      t.first = e;
    }
    else if (t.second.sum < e.sum) {
      t.second = e;
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Elem& e) {
  os << "(" << (e.sum == -INF ? "-oo" : to_string(e.sum)) << ", " << e.kind << ")";
  return os;
}

int main() {
  mt19937 rng(0);

  int n;
  cin >> n;
  vector<int> kind(n);
  vector<lint> val(n);
  rep (i, n) cin >> kind[i] >> val[i], kind[i]--;

  lint ans = -1;
  rep (_, 500) {
    // color coding
    vector<int> color(n);
    rep (k, n) color[k] = (rng() % 3 < 2 ? 0 : 1);

    vector dp(n + 1, array<Top2, 6>());
    rep (j, 6) {
      dp[0][j] = {
          Elem{-INF, -1},
          Elem{-INF, -1}
      };
    }
    rep (i, n) {
      dp[i + 1] = dp[i];

      if (color[kind[i]] == 0) {
        // dp[i + 1][0]
        update(dp[i + 1][0], Elem{val[i], kind[i]});
        // dp[i + 1][1]
        for (auto e: {dp[i][0].first, dp[i][0].second}) {
          if (e.sum != -INF && e.kind != kind[i])
            update(dp[i + 1][1], Elem{e.sum + val[i], kind[i]});
        }
        // dp[i + 1][4]
        if (dp[i][3].first.sum != -INF) {
          update(dp[i + 1][4], Elem{dp[i][3].first.sum + val[i], kind[i]});
        }
        // dp[i + 1][5]
        for (auto e: {dp[i][4].first, dp[i][4].second}) {
          if (e.sum != -INF && e.kind != kind[i])
            update(dp[i + 1][5], Elem{e.sum + val[i], kind[i]});
        }
      }
      else {
        // dp[i + 1][2]
        if (dp[i][1].first.sum != -INF) {
          update(dp[i + 1][2], Elem{dp[i][1].first.sum + val[i], kind[i]});
        }
        // dp[i + 1][3]
        for (auto e: {dp[i][2].first, dp[i][2].second}) {
          if (e.sum != -INF && e.kind != kind[i])
            update(dp[i + 1][3], Elem{e.sum + val[i], kind[i]});
        }
      }
    }

    chmax(ans, dp[n][5].first.sum);
  }
  cout << ans << endl;

  return 0;
}
