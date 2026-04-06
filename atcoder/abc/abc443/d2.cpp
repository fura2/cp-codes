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
void add_directed_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G, int s) {
    constexpr T INF = numeric_limits<T>::max();

    int n = G.size();
    vector<T> d(n, INF);
    d[s] = T{};
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> Q;
    Q.emplace(T{}, s);
    while (!Q.empty()) {
        T d0;
        int u;
        tie(d0, u) = Q.top();
        Q.pop();
        if (d0 > d[u]) continue;
        for (const auto& [v, wt]: G[u]) {
            if (d[v] > d[u] + wt) {
                d[v] = d[u] + wt;
                Q.emplace(d[v], v);
            }
        }
    }
    return d;
}

void solve() {
    int n;
    cin >> n;
    vector<lint> r(n);
    rep (i, n) cin >> r[i], r[i]--;

    weighted_graph<lint> G(n + 1);
    rep (i, n) {
        add_directed_edge(G, n, i, r[i]);
    }
    rep (i, n - 1) {
        add_directed_edge(G, i, i + 1, 1LL);
        add_directed_edge(G, i + 1, i, 1LL);
    }

    auto d = Dijkstra(G, n);
    cout << accumulate(all(r), 0LL) - accumulate(all(d), 0LL) << endl;
}

int main() {
    int t;
    cin >> t;
    rep (_, t) solve();
    return 0;
}
