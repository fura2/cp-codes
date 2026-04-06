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

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

void add_directed_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
}

template<class G>
class Fenwick_tree_dual {
    vector<G> a;

  public:
    Fenwick_tree_dual(int n = 0) {
        build(n);
    }
    Fenwick_tree_dual(const vector<G>& a) {
        build(a);
    }
    void build(int n) {
        a.assign(n, G{});
    }
    void build(const vector<G>& a) {
        this->a = a;
        for (int i = 1; i <= a.size(); i++)
            if (i + (i & -i) <= a.size()) (this->a)[i - 1] -= (this->a)[i + (i & -i) - 1];
    }
    void add(int l, int r, const G& val) {
        if (l == 0) {
            for (; r > 0; r -= r & -r) a[r - 1] += val;
            return;
        }
        add(0, r, val);
        add(0, l, -val);
    }
    G get(int i) const {
        G res{};
        for (i++; i <= a.size(); i += i & -i) res += a[i - 1];
        return res;
    }
};

constexpr int INF = 1 << 29;

int main() {
    int n, m;
    cin >> n >> m;
    graph G(n);
    vector<int> par(n, -1);
    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        add_directed_edge(G, u, v);
        if (par[v] == -1)
            par[v] = u;
        else
            chmin(par[v], u);
    }

    // Dijkstra-like
    vector<int> d(n, INF);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    Q.emplace(0, 0);
    while (!Q.empty()) {
        auto [d0, u] = Q.top();
        Q.pop();
        if (d0 > d[u]) continue;
        for (int v: G[u]) {
            if (chmin(d[v], max(d[u], v))) {
                Q.emplace(d[v], v);
            }
        }
    }

    vector<bool> conn(n);
    int mx = 0;
    rep (u, n) {
        chmax(mx, d[u]);
        conn[u] = (mx == u);
    }

    Fenwick_tree_dual<int> F(n);
    rep (u, n) {
        if (par[u] == -1 || par[u] >= u) continue;
        F.add(par[u], u, 1);
    }

    rep (u, n) {
        if (!conn[u]) {
            cout << -1 << endl;
        }
        else {
            cout << F.get(u) << endl;
        }
    }
    return 0;
}
