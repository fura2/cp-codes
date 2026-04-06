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

void solve() {
    int n;
    lint m;
    cin >> n >> m;
    vector<lint> a(n);
    rep (i, n) cin >> a[i];

    // cand[i] = (a[i] についての操作で現れうる数の昇順リスト)
    vector cand(n, vector<lint>());
    // cand[i][j] を割ると cand[i][to[i][j][0/1]] に分かれる
    vector to(n, vector<vector<int>>());
    rep (i, n) {
        cand[i].emplace_back(a[i]);
        lint x = a[i];
        while (x > 0) {
            rep (d, 2) {
                if (x / 2 + d > 0) cand[i].emplace_back(x / 2 + d);
            }
            x /= 2;
        }
        sort(all(cand[i]));
        cand[i].erase(unique(all(cand[i])), cand[i].end());

        to[i] = vector(cand[i].size(), vector<int>(2, -1));
        rep (j, cand[i].size()) {
            rep (d, 2) {
                lint x = (cand[i][j] + d) / 2;
                if (x > 0) {
                    to[i][j][d] = lower_bound(all(cand[i]), x) - cand[i].begin();
                }
            }
        }
    }

    // median を tar 以上にできるかどうか
    auto check = [&](lint tar) {
        lint half = (n + m + 1) / 2;

        // small: tar より小さい数, large: tar 以上の数
        lint n_large = 0;
        rep (i, n) {
            if (a[i] >= tar) n_large++;
        }
        // m が足りない
        if (m < half - n_large) return false;

        vector<pair<lint, lint>> large;
        rep (i, n) {
            if (a[i] < tar) continue;

            // a[i] を分割する過程のシミュレーション
            // x は、(x+1)/2, x/2 の少なくとも一方が large である間、割り続ける
            vector<lint> H(cand[i].size()); // histogram over cand[i]
            H[cand[i].size() - 1]++;
            rrep (j, cand[i].size()) {
                lint x = cand[i][j];
                lint c = H[j];
                if (c == 0) continue;

                if (x / 2 >= tar) {
                    // (x+1)/2, x/2 のどちらも large
                    H[j] -= c;
                    H[to[i][j][0]] += c;
                    H[to[i][j][1]] += c;
                    n_large += c;
                }
                else if ((x + 1) / 2 >= tar) {
                    // (x+1)/2 は large, x/2 は small
                    H[j] -= c;
                    H[to[i][j][1]] += c;
                }
                else {
                    // (x+1)/2, x/2 のどちらも small
                    break;
                }
            }

            rrep (j, cand[i].size()) {
                lint x = cand[i][j];
                lint c = H[j];
                if (c == 0) continue;
                large.emplace_back(x, c);
            }
        }
        if (n_large < half) { // 十分多くの large が作れなかった
            return false;
        }

        // 操作後の large から小さい順に half 個選んで残す
        lint rem = 0; // 残したものの長さの合計
        sort(all(large));
        for (lint h = half; auto [x, c]: large) {
            lint c2 = min(c, h);
            rem += x * c2;
            h -= c2;
        }
        // これら half 個以外を全部 1 まで分解するのに、
        // (Σ_i a_i - n) - (rem - half) 回の操作を消費できる
        return (accumulate(all(a), 0LL) - n) - (rem - half) >= m;
    };

    lint lo = 1, hi = *max_element(all(a)) + 1;
    while (hi - lo > 1) {
        lint mi = (lo + hi) / 2;
        if (check(mi))
            lo = mi;
        else
            hi = mi;
    }
    cout << lo << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
