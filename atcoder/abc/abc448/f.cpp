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

struct point {
  lint x, y;
  int i;
};

lint dist(const point& p, const point& q) {
  return abs(p.x - q.x) + abs(p.y - q.y);
}

int main() {
  int n;
  cin >> n;
  vector<point> p(n);
  rep (i, n) cin >> p[i].x >> p[i].y, p[i].i = i;

  constexpr lint D = 200000;
  constexpr lint M = 20000000;
  constexpr lint K = M / D + 1;

  vector idx(K, vector<int>(K));
  {
    int cnt = 0;
    rep (i, K) {
      if (i % 2 == 0) {
        rep (j, K) idx[i][j] = cnt++;
      }
      else {
        rrep (j, K) idx[i][j] = cnt++;
      }
    }
  }
  sort(all(p), [&](const auto& a, const auto& b) {
    return idx[a.x / D][a.y / D] < idx[b.x / D][b.y / D];
  });

  int i0 = 0;
  rep (i, n)
    if (p[i].i == 0) {
      i0 = i;
      break;
    }
  rotate(p.begin(), p.begin() + i0, p.end());

  int cnt = 0;
  while (true) {
    bool ok = true;
    rep (i, 1, n - 2) {
      point& a = p[(i - 1) % n];
      point& b = p[i % n];
      point& c = p[(i + 1) % n];
      point& d = p[(i + 2) % n];
      if (dist(a, b) + dist(c, d) > dist(a, c) + dist(b, d)) {
        swap(b, c);
        ok = false;
      }
    }
    if (ok) break;
    cnt++;
  }

  rep (i, n) cout << p[i % n].i + 1 << " ";

  return 0;
}
