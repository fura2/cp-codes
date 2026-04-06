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

int main() {
    int n;
    lint c;
    cin >> n >> c;
    vector<lint> w(n), v(n), k(n);
    rep (i, n) cin >> w[i] >> v[i] >> k[i];

    vector A(4, vector<int>());
    rep (i, n) A[w[i]].emplace_back(i);
    rep (x, 1, 4) {
        sort(all(A[x]), [&](int i, int j) { return v[i] > v[j]; });
    }

    lint ans = 0;
    rep (r1, 6) {
        rep (r2, 3) {
            rep (r3, 2) {
                lint c_small = r1 + 2 * r2 + 3 * r3;
                if (c_small > c) continue;

                lint v_small = 0;
                vector<lint> k_large = k;
                int m[] = {0, r1, r2, r3};
                rep (x, 1, 4) {
                    for (int i: A[x]) {
                        rep (_, k[i]) {
                            if (m[x] == 0) break;
                            v_small += v[i];
                            k_large[i]--;
                            m[x]--;
                        }
                    }
                }
                if (count(m + 1, m + 4, 0) != 3) {
                    continue; // Not enough small items
                }

                vector<pair<lint, lint>> items; // (value, num) items of weight 6
                rep (x, 1, 4) {
                    int num = 0;
                    lint vsum = 0;

                    for (int i: A[x]) {
                        while (true) {
                            if (num == 0 && k_large[i] >= 6 / x) {
                                // アイテム i だけで重さ 6 を作る
                                items.emplace_back((6 / x) * v[i], k_large[i] / (6 / x));
                                k_large[i] %= 6 / x;
                            }
                            if (k_large[i] == 0) break;

                            // 複数のアイテムが混ざる
                            k_large[i]--;
                            num++;
                            vsum += v[i];
                            if (num == 6 / x) {
                                items.emplace_back(vsum, 1);
                                num = 0;
                                vsum = 0;
                            }
                        }
                    }
                }
                sort(all(items), greater<pair<lint, lint>>());

                lint c_large = (c - c_small) / 6;
                lint v_large = 0;
                for (auto [val, num]: items) {
                    chmin(num, c_large);
                    c_large -= num;
                    v_large += num * val;
                }
                chmax(ans, v_small + v_large);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
