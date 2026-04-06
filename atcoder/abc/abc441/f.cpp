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

const lint INF = 1LL << 61;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> c(n);
    vector<lint> v(n);
    rep (i, n) cin >> c[i] >> v[i];

    vector dpl(n + 1, vector(w + 1, -INF));
    dpl[0][0] = 0;
    rep (i, n) {
        rep (x, w + 1) dpl[i + 1][x] = dpl[i][x];
        for (int x = w; x >= c[i]; x--) {
            dpl[i + 1][x] = max(dpl[i + 1][x], dpl[i][x - c[i]] + v[i]);
        }
    }

    vector dpr(n + 1, vector(w + 1, -INF));
    dpr[0][0] = 0;
    rep (i, n) {
        rep (x, w + 1) dpr[i + 1][x] = dpr[i][x];
        for (int x = w; x >= c[n - i - 1]; x--) {
            dpr[i + 1][x] = max(dpr[i + 1][x], dpr[i][x - c[n - i - 1]] + v[n - i - 1]);
        }
    }

    rep (i, n + 1) {
        rep (x, w) {
            dpl[i][x + 1] = max(dpl[i][x + 1], dpl[i][x]);
            dpr[i][x + 1] = max(dpr[i][x + 1], dpr[i][x]);
        }
    }

    lint opt = *max_element(all(dpl[n]));
    string ans(n, 'B');
    rep (i, n) {
        bool isa = true;
        rep (x, w + 1) {
            if (dpl[i][x] + dpr[n - i - 1][w - x] == opt) {
                isa = false;
                break;
            }
        }

        bool isc = true;
        rep (x, w - c[i] + 1) {
            if (dpl[i][x] + v[i] + dpr[n - i - 1][w - c[i] - x] == opt) {
                isc = false;
                break;
            }
        }

        if (isa) {
            ans[i] = 'A';
        }
        else if (isc) {
            ans[i] = 'C';
        }
    }
    cout << ans << endl;

    return 0;
}
