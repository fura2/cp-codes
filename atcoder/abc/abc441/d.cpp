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

template<class T>
struct edge {
    int to;
    T wt;
    edge(int to, const T& wt): to(to), wt(wt) {}
};
template<class T>
using weighted_graph = vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
    G[v].emplace_back(u, wt);
}

template<class T>
void add_directed_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
}

weighted_graph<lint> G;

int l;
lint c_min, c_max;
bool ans[200000];

void dfs(int u, int t, lint c) {
    if (t == l) {
        if (c_min <= c && c <= c_max) {
            ans[u] = true;
        }
        return;
    }
    for (auto& e: G[u]) {
        dfs(e.to, t + 1, c + e.wt);
    }
}

int main() {
    int n, m;
    cin >> n >> m >> l >> c_min >> c_max;
    G = weighted_graph<lint>(n);
    rep (i, m) {
        int u, v;
        lint c;
        cin >> u >> v >> c;
        u--;
        v--;
        add_directed_edge(G, u, v, c);
    }

    dfs(0, 0, 0LL);
    rep (u, n)
        if (ans[u]) cout << u + 1 << " ";
    cout << endl;

    return 0;
}
