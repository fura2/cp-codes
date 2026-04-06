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

struct Block {
    int h, w;
};

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<Block> B(n);
    rep (i, n) cin >> B[i].h >> B[i].w;

    set<pair<int, int>> S1, S2;
    rep (i, n) {
        S1.emplace(-B[i].h, i);
        S2.emplace(-B[i].w, i);
    }

    vector<pair<int, int>> ans(n);
    int ofsx = 0, ofsy = 0;
    rep (_, n) {
        int i1 = S1.begin()->second;
        int i2 = S2.begin()->second;
        if (B[i1].h == h - ofsy) {
            ans[i1] = {ofsx, ofsy};
            ofsx += B[i1].w;
            S1.erase({-B[i1].h, i1});
            S2.erase({-B[i1].w, i1});
        }
        else {
            assert(B[i2].w == w - ofsx);
            ans[i2] = {ofsx, ofsy};
            ofsy += B[i2].h;
            S1.erase({-B[i2].h, i2});
            S2.erase({-B[i2].w, i2});
        }
    }
    rep (i, n) cout << ans[i].second + 1 << " " << ans[i].first + 1 << endl;

    return 0;
}
