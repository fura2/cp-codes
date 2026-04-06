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

class suffix_array {
  vector<int> sa, lcp;

  vector<int> cnt;

  void SA_IS(vector<int>& s, int k) {
    int n = s.size();

    for (int& c: s) c++;
    s.emplace_back(0);
    k++;

    vector<bool> isS(n + 1);
    vector<int> LMS, bin(k + 1);
    isS[n] = true;
    bin[1] = 1;
    for (int i = n - 1; i >= 0; i--) {
      isS[i] = (s[i] != s[i + 1] ? s[i] < s[i + 1] : isS[i + 1]);
      if (!isS[i] && isS[i + 1]) {
        LMS.emplace_back(i + 1);
      }
      bin[s[i] + 1]++;
    }
    rep (i, k) bin[i + 1] += bin[i];

    auto induced_sort = [&](const vector<int>& LMS) {
      sa.assign(n + 1, -1);
      cnt.assign(k, 0);
      for (int x: LMS) {
        sa[bin[s[x] + 1] - cnt[s[x]] - 1] = x;
        cnt[s[x]]++;
      }

      cnt.assign(k, 0);
      rep (i, n + 1) {
        int x = sa[i] - 1;
        if (x >= 0 && !isS[x]) {
          sa[bin[s[x]] + cnt[s[x]]] = x;
          cnt[s[x]]++;
        }
      }

      cnt.assign(k, 0);
      for (int i = n; i >= 0; i--) {
        int x = sa[i] - 1;
        if (x >= 0 && isS[x]) {
          sa[bin[s[x] + 1] - cnt[s[x]] - 1] = x;
          cnt[s[x]]++;
        }
      }
    };

    induced_sort(LMS);

    if (LMS.size() <= 1) return;

    int m = LMS.size();
    vector<int> inv(n + 1, -1);
    rep (i, m) inv[LMS[i]] = i;

    int idx = 0;
    vector<int> LMS2(m);
    for (int x: sa)
      if (inv[x] != -1) LMS2[idx++] = x;

    int k2 = 1;
    vector<int> s2(m);
    s2[m - 1 - inv[LMS2[1]]] = 1;
    for (int i = 2; i < m; i++) {
      int xl = LMS2[i], yl = LMS2[i - 1];
      int xr = LMS[inv[xl] - 1], yr = LMS[inv[yl] - 1];
      if (xr - xl != yr - yl)
        k2++;
      else {
        while (xl <= xr) {
          if (s[xl] != s[yl]) {
            k2++;
            break;
          }
          xl++;
          yl++;
        }
      }
      s2[m - 1 - inv[LMS2[i]]] = k2;
    }

    SA_IS(s2, k2 + 1);

    idx = m;
    for (int i = 1; i <= m; i++) LMS2[--idx] = LMS[m - sa[i] - 1];
    induced_sort(LMS2);
  }

  void build_lcp(const vector<int>& s) {
    int n = s.size();
    lcp.resize(n);
    vector<int> f(n + 1);
    rep (i, n + 1) f[sa[i]] = i;
    int h = 0;
    rep (i, n + 1) {
      if (f[i]) {
        for (int j = sa[f[i] - 1]; i + h < n && j + h < n; h++)
          if (s[i + h] != s[j + h]) break;
        lcp[f[i] - 1] = h;
      }
      if (h > 0) h--;
    }
  }

 public:
  suffix_array(const string& s) {
    int n = s.length();
    if (n == 0) {
      sa = {0};
      return;
    }

    auto p = minmax_element(s.begin(), s.end());
    char mn = *p.first, mx = *p.second;

    vector<int> t(n);
    rep (i, n) t[i] = s[i] - mn;

    SA_IS(t, mx - mn + 1);

    t.resize(n);
    rep (i, n) t[i] = s[i] - mn;
    build_lcp(t);
  }

  suffix_array(const vector<int>& a) {
    int n = a.size();
    if (n == 0) {
      sa = {0};
      return;
    }

    vector<int> X = a, b(n);
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    rep (i, n) b[i] = lower_bound(X.begin(), X.end(), a[i]) - X.begin();

    SA_IS(b, X.size());

    build_lcp(a);
  }

  int operator[](int i) const {
    return sa[i];
  }

  const vector<int>& longest_common_prefix() const {
    return lcp;
  }
};

template<class T>
vector<pair<T, int>> run_length_encoding(const vector<T>& a) {
  vector<pair<T, int>> res;
  int n = a.size(), pre = 0;
  rep (i, n)
    if (i == n - 1 || a[i] != a[i + 1])
      res.emplace_back(a[i], i - pre + 1), pre = i + 1;
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  vector<int> b;
  for (auto [c, k]: run_length_encoding(a)) {
    if (c == k) {
      b.emplace_back(c);
    }
    else if (c < k) {
      b.emplace_back(c);
      b.emplace_back(-1);
      b.emplace_back(c);
    }
    else {
      b.emplace_back(-1);
    }
  }
  vector<int> bad;
  rep (i, b.size())
    if (b[i] == -1) bad.emplace_back(i);
  bad.emplace_back(b.size()); // sentinel

  suffix_array S(b);
  auto lcp = S.longest_common_prefix();

  lint ans = 0;
  rep (i, b.size()) {
    int pos = *lower_bound(all(bad), S[i + 1]);
    ans += max(pos - S[i + 1] - lcp[i], 0);
  }
  cout << ans << endl;

  return 0;
}
