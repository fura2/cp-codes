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

int n, cnt;
vector<vector<int>> A;

void dfs(int i, int j, vector<pair<int, int>>& p) {
    if (i == n - 1 && j == n - 1) {
        int sum = 0;
        int ti = -1, tj;
        for (auto [i2, j2]: p) {
            if (A[i2][j2] == -1) {
                assert(ti == -1);
                ti = i2;
                tj = j2;
            }
            else
                sum += A[i2][j2];
        }
        if (ti != -1) A[ti][tj] = cnt - sum;
        cnt++;
        return;
    }

    if (j < n - 1) {
        p.emplace_back(i, j + 1);
        dfs(i, j + 1, p);
        p.pop_back();
    }
    if (i < n - 1) {
        p.emplace_back(i + 1, j);
        dfs(i + 1, j, p);
        p.pop_back();
    }
}

int main() {
    cin >> n;

    A.assign(n, vector(n, -1));
    rep (i, n) A[0][i] = A[i][n - 1] = 0;
    A[n - 1][n - 1] = -1;

    vector<pair<int, int>> p = {
        {0, 0}
    };
    dfs(0, 0, p);

    rep (i, n) {
        rep (j, n) cout << A[i][j] << " ";
        cout << endl;
    }

    return 0;
}
