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

const int INF = 1 << 29;

int main() {
    int n;
    cin >> n;

    int a_min = -1;
    vector len((n + 1) * 10, INF);
    len[10 * n + 1] = 0;
    vector prev((n + 1) * 10, -1);

    queue<int> Q;
    Q.emplace(10 * n + 1);
    while (!Q.empty()) {
        auto a = Q.front();
        Q.pop();
        auto [x, d] = pair(a / 10, a % 10);

        if (x == 0) {
            a_min = a;
            break;
        }

        rep (d2, d, 10) {
            int x2 = (10 * x + d2) % n;
            int a2 = 10 * x2 + d2;

            // This pruning improves time complexity from O(Nσ^2) to O(Nσ)
            if (len[a2] < INF) break;

            len[a2] = len[a] + 1;
            prev[a2] = a;
            Q.emplace(a2);
        }
    }

    if (a_min == -1) {
        cout << -1 << endl;
        return 0;
    }

    // reconstruct
    string ans;
    for (int a = a_min; a / 10 != n; a = prev[a]) {
        ans += a % 10 + '0';
    }
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}
