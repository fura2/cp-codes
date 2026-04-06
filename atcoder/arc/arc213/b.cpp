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

// parity of popcount
int f(lint x) {
    return popcount(ulint(x)) % 2;
}

lint solve0(lint l, lint r) {
    lint n = r - l + 1;

    if (l % 2 == 0 && r % 2 == 1) {
        return n / 2;
    }
    if (l % 2 == r % 2) {
        return n / 2 + 1;
    }

    // l % 2 == 1 && r % 2 == 0
    if (f(l) == f(r)) {
        return n / 2 + 1;
    }

    int b = 60;
    while (bit(l, b) == bit(r, b)) b--;
    if (l + (1LL << b) > r) {
        return n / 2 + 1;
    }
    return n / 2;
}

string solve1(lint l, lint r) {
    lint n = r - l + 1;

    int par;
    if (l % 2 == 0 && r % 2 == 1) {
        par = f(l); // 端数なし
    }
    else if (l % 2 == 0 && r % 2 == 0) {
        par = f(r); // use r
    }
    else if (l % 2 == 1 && r % 2 == 1) {
        par = f(l); // use l
    }
    else if (f(l) == f(r)) {
        par = f(l); // use both l and r
    }
    else {
        int b = 60; // the highest bit s.t. bit(l, b) == 0 and bit(r, b) == 1
        while (bit(l, b) == bit(r, b)) b--;
        if ((l | (1LL << b)) > r) {
            // mixed case
            lint c = (l | (1LL << b)) & ~((1LL << b) - 1);
            string res(n, '0');
            rep (i, n) {
                if (l + i < c) { // first half
                    par = f(l);
                }
                else { // second half
                    par = f(r);
                }
                if (f(l + i) == par) res[i] = '1';
            }
            return res;
        }

        par = f(l); // use either l or r
    }

    string res(n, '0');
    rep (i, n)
        if (f(l + i) == par) res[i] = '1';
    return res;
}

void solve() {
    int q;
    lint l, r;
    cin >> q >> l >> r;
    if (q == 0)
        cout << solve0(l, r) << endl;
    else
        cout << solve1(l, r) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
