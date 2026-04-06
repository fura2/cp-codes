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

pair<bool, vector<int>> two_coloring(const graph& G) {
    int n = G.size();
    vector<int> color(n, -1);
    rep (u, n)
        if (color[u] == -1) {
            color[u] = 0;
            queue<int> Q;
            Q.emplace(u);
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                for (int w: G[v]) {
                    if (color[w] == -1) {
                        color[w] = 1 - color[v];
                        Q.emplace(w);
                    }
                    else if (color[w] == color[v])
                        return {false, vector<int>()};
                }
            }
        }
    return {true, color};
}

// Hopcroft-Karp from my old library
constexpr int V_MAX = 300 * 300;
int layer[V_MAX];
int match[2][V_MAX];

bool make_layer(int L, const graph& G, int match[2][V_MAX]) {
    queue<int> Q;
    rep (u, L) {
        if (match[0][u] == -1) {
            layer[u] = 0;
            Q.push(u);
        }
        else
            layer[u] = -1;
    }
    bool res = false;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        rep (i, G[u].size()) {
            int v = match[1][G[u][i]];
            if (v == -1)
                res = true;
            else if (layer[v] == -1) {
                layer[v] = layer[u] + 1;
                Q.push(v);
            }
        }
    }
    return res;
}

bool augment(int u, const graph& G, int match[2][V_MAX]) {
    if (u == -1) return true;
    rep (i, G[u].size()) {
        int v = G[u][i], w = match[1][v];
        if (w == -1 || layer[u] + 1 == layer[w]) {
            if (augment(w, G, match)) {
                match[0][u] = v;
                match[1][v] = u;
                return true;
            }
        }
    }
    layer[u] = -3; // 訪問済みのマーク
    return false;
}

int Hopcroft_Karp(int L, int R, const graph& G) {
    rep (u, L) match[0][u] = -1;
    rep (v, R) match[1][v] = -1;
    int res = 0;
    while (make_layer(L, G, match)) {
        rep (u, L)
            if (match[0][u] == -1 && augment(u, G, match)) res++;
    }
    return res;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<string> B(n);
    rep (i, n) cin >> B[i];

    vector<pair<int, int>> ds = {
        {a,  b },
        {a,  -b},
        {-a, b },
        {-a, -b},
        {b,  a },
        {b,  -a},
        {-b, a },
        {-b, -a},
    };
    int N = n * n;
    graph G(N);
    rep (i, n) {
        rep (j, n) {
            if (B[i][j] == '#') continue;
            for (auto [dx, dy]: ds) {
                int x = i + dx, y = j + dy;
                if (!(i <= x && x < n && 0 <= y && y < n && B[x][y] == '.')) continue;
                int u = i * n + j, v = x * n + y;
                if (u < v) {
                    add_undirected_edge(G, u, v);
                }
            }
        }
    }
    auto color = two_coloring(G).second;

    vector<int> L, R, f(N);
    rep (i, n) {
        rep (j, n) {
            if (B[i][j] == '#') continue;
            int u = i * n + j;
            if (color[u] == 0) {
                f[u] = L.size();
                L.emplace_back(u);
            }
            else {
                f[u] = R.size();
                R.emplace_back(u);
            }
        }
    }
    int nl = L.size(), nr = R.size();

    graph H(nl);
    rep (u, N) {
        for (int v: G[u]) {
            if (color[u] == 0)
                H[f[u]].emplace_back(f[v]);
            else
                H[f[v]].emplace_back(f[u]);
        }
    }

    Hopcroft_Karp(nl, nr, H);

    // Reconstruct minimum vertex cover
    array<vector<bool>, 2> vis = {vector<bool>(nl), vector<bool>(nr)};
    queue<pair<int, int>> Q;
    rep (u, nl) {
        if (match[0][u] == -1) {
            vis[0][u] = true;
            Q.emplace(0, u);
        }
    }
    while (!Q.empty()) {
        auto [p, u] = Q.front();
        Q.pop();
        if (p == 0) {
            for (int v: H[u]) {
                if (!vis[1][v] && match[0][u] != v) {
                    vis[1][v] = true;
                    Q.emplace(1, v);
                }
            }
        }
        else {
            int v = match[1][u];
            if (v != -1 && !vis[0][v]) {
                vis[0][v] = true;
                Q.emplace(0, v);
            }
        }
    }
    rep (i, n)
        rep (j, n)
            if (B[i][j] == '.') B[i][j] = 'o';
    rep (u, nl) {
        if (!vis[0][u]) {
            int v = L[u];
            int i = v / n, j = v % n;
            B[i][j] = '.';
        }
    }
    rep (u, nr) {
        if (vis[1][u]) {
            int v = R[u];
            int i = v / n, j = v % n;
            B[i][j] = '.';
        }
    }

    rep (i, n) cout << B[i] << endl;

    return 0;
}
