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
    int n, q;
    cin >> n >> q;
    vector<lint> a(n);
    vector<int> b(n);
    rep (i, n) cin >> a[i] >> b[i];

    lint sum = accumulate(all(a), 0LL);
    lint sum_hi = 0;
    int m = count(all(b), 2);
    int m_hi = 0;
    // 上位 m 個, 下位 n-m 個 (b==1 が優先的に上位に入るようにタイブレーク)
    set<tuple<lint, int, int>> H, L;

    auto balance = [&]() {
        while (H.size() < m) {
            // move an element from L to H
            int i = get<2>(*L.begin());
            H.emplace(-a[i], b[i], i);
            L.erase({-a[i], b[i], i});
            sum_hi += a[i];
            if (b[i] == 2) {
                m_hi++;
            }
        }
        while (H.size() > m) {
            // move an element from H to L
            int i = get<2>(*H.rbegin());
            H.erase({-a[i], b[i], i});
            L.emplace(-a[i], b[i], i);
            sum_hi -= a[i];
            if (b[i] == 2) {
                m_hi--;
            }
        }
    };

    rep (i, n) L.emplace(-a[i], b[i], i);
    balance();

    rep (_, q) {
        int i, y;
        lint x;
        cin >> i >> x >> y;
        i--;

        // delete
        if (H.contains({-a[i], b[i], i})) {
            H.erase({-a[i], b[i], i});
            sum_hi -= a[i];
            if (b[i] == 2) {
                m_hi--;
            }
        }
        else {
            L.erase({-a[i], b[i], i});
        }
        sum -= a[i];
        if (b[i] == 2) {
            m--;
        }

        a[i] = x;
        b[i] = y;

        // add
        sum += a[i];
        if (b[i] == 2) {
            m++;
        }
        if (!H.empty() && *H.rbegin() >= make_tuple(-a[i], b[i], i)) {
            H.emplace(-a[i], b[i], i);
            sum_hi += a[i];
            if (b[i] == 2) {
                m_hi++;
            }
        }
        else {
            L.emplace(-a[i], b[i], i);
        }
        balance();

        if (m_hi < m) {
            cout << sum + sum_hi << endl;
        }
        else if (m == 0) {
            cout << sum << endl;
        }
        else if (m == n) {
            lint a_hi = -get<0>(*H.rbegin());
            cout << sum + sum_hi - a_hi << endl;
        }
        else {
            lint a_hi = -get<0>(*H.rbegin());
            lint a_lo = -get<0>(*L.begin());
            cout << sum + sum_hi - a_hi + a_lo << endl;
        }
    }

    return 0;
}
