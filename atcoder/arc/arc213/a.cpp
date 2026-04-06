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

const int INF = 1 << 29;

int f[9], g[9];
int inversion_number(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    rep (i, n) f[a[i]] = i;
    rep (i, n) g[i] = f[b[i]];

    int res = 0;
    rep (i, n)
        rep (j, i + 1, n)
            if (g[i] > g[j]) res++;
    return res;
}

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> c(n + 1);
    vector p(n + 1, vector(l, -1));
    iota(all(p[0]), 0);
    rep (i, 1, n + 1) {
        cin >> c[i];
        rep (j, l) cin >> p[i][j], p[i][j]--;
    }

    int m = l * (l - 1) / 2; // max of inversion number

    vector<int> dp(n + 1, -INF);
    dp[0] = 0;
    int cummax = -INF;
    rep (i, 1, n + 1) {
        rep (d, 1, m + 1) {
            if (i - d < 0) continue;
            if (inversion_number(p[i], p[i - d]) <= d) {
                chmax(dp[i], dp[i - d] + c[i]);
            }
        }
        if (i - m - 1 >= 0) {
            chmax(cummax, dp[i - m - 1]);
            chmax(dp[i], cummax + c[i]);
        }
    }
    cout << *max_element(all(dp)) << endl;

    return 0;
}
