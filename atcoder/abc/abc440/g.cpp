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

class union_find {
    int n;
    vector<int> p;

  public:
    union_find(int n = 0) {
        build(n);
    }
    void build(int n) {
        this->n = n;
        p.assign(n, -1);
    }
    int find(int u) {
        return p[u] < 0 ? u : p[u] = find(p[u]);
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (p[v] < p[u]) swap(u, v);
            p[u] += p[v];
            p[v] = u;
            n--;
        }
    }
    bool is_same(int u, int v) {
        return find(u) == find(v);
    }
    int size() const {
        return n;
    }
    int size(int u) {
        return -p[find(u)];
    }
};

using graph = vector<vector<int>>;

void add_directed_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
}

const int INF = 1 << 29;

int main() {
    int l, h, w;
    cin >> l >> h >> w;
    vector B(l, vector<string>(h));
    rep (k, l)
        rep (i, h) cin >> B[k][i];

    int n = 0;
    vector<int> val; // weight of vertices
    map<pair<int, int>, int> f; // (k, representative of U[k]) -> vertex
    vector U(l, union_find(h * w));
    rep (k, l) {
        rep (i, h) {
            rep (j, w) {
                if (B[k][i][j] == '#') continue;
                if (i < h - 1 && B[k][i + 1][j] != '#') {
                    U[k].unite(i * w + j, (i + 1) * w + j);
                }
                if (j < w - 1 && B[k][i][j + 1] != '#') {
                    U[k].unite(i * w + j, i * w + (j + 1));
                }
            }
        }
        rep (i, h) {
            rep (j, w) {
                if (B[k][i][j] == '#') continue;

                int r = U[k].find(i * w + j);
                if (!f.contains({k, r})) {
                    f[{k, r}] = n;
                    n++;
                    val.emplace_back(0);
                }

                int u = f[{k, r}];
                val[u] += B[k][i][j] - '0';
            }
        }
    }

    set<pair<int, int>> E; // edges
    rep (k, l - 1) {
        rep (i, h) {
            rep (j, w) {
                if (B[k][i][j] == '#' || B[k + 1][i][j] == '#') continue;
                int u = f[{k, U[k].find(i * w + j)}];
                int v = f[{k + 1, U[k + 1].find(i * w + j)}];
                E.emplace(u, v);
            }
        }
    }

    graph D(n), rD(n); // DAG, reversed
    for (auto [u, v]: E) {
        add_directed_edge(D, u, v);
        add_directed_edge(rD, v, u);
    }

    auto update_top2 = [](array<int, 2>& a, int v, array<int, 2>& prev, int x) {
        if (v >= a[0]) {
            if (prev[0] == x) {
                // 元々 1 位だったものが更新されるなら、2 位はそのまま
                a[0] = v;
                prev[0] = x;
            }
            else {
                a[1] = a[0];
                prev[1] = prev[0];
                a[0] = v;
                prev[0] = x;
            }
        }
        else if (v >= a[1]) {
            if (prev[0] != x) {
                a[1] = v;
                prev[1] = x;
            }
        }
    };

    // dp1[u] = 頂点 u から始めて、次の移動では逆走せず、
    //          その後にちょうど 1 回逆走するときの、通った頂点の重みの和の最大値
    // dp2[u] = 頂点 u から始めて、次の移動で逆走し、
    //          その後逆走しないときの、通った頂点の重みの和 top 2
    // dp3[u] = 頂点 u から始めて、一度も逆走しないときの、通った頂点の重みの和 top 2
    vector dp1(n, -INF);
    vector<array<int, 2>> dp2(n, {-INF, -INF});
    vector<array<int, 2>> dp3(n, {-INF, -INF});
    vector<array<int, 2>> prev2(n, {-1, -1});
    vector<array<int, 2>> prev3(n, {-1, -1});
    // compute dp3
    rrep (u, n) {
        update_top2(dp3[u], val[u], prev3[u], -1); // ここで終わる
        for (int v: D[u]) {
            rep (i, 2) {
                update_top2(dp3[u], dp3[v][i] + val[u], prev3[u], v);
            }
        }
    }
    // compute dp2
    rrep (u, n) {
        for (int v: rD[u]) {
            rep (i, 2) {
                if (prev3[v][i] == u) {
                    // 上がって、引き返す
                    update_top2(dp2[u], dp3[v][i], prev2[u], v);
                }
                else {
                    // 上がって、別方向に下る
                    update_top2(dp2[u], dp3[v][i] + val[u], prev2[u], v);
                }
            }
        }
    }
    // compute dp1
    rrep (u, n) {
        for (int v: D[u]) {
            chmax(dp1[u], dp1[v] + val[u]);
            rep (i, 2) {
                if (prev2[v][i] == u) {
                    // 下がって、引き返す
                    chmax(dp1[u], dp2[v][i]);
                }
                else {
                    // 下がって、別方向に上がる
                    chmax(dp1[u], dp2[v][i] + val[u]);
                }
            }
        }
    }

    int q;
    cin >> q;
    rep (_, q) {
        int k, i, j;
        cin >> k >> i >> j;
        k--, i--, j--;
        int u = f[{k, U[k].find(i * w + j)}];
        cout << max({dp1[u], dp2[u][0], dp3[u][0]}) << endl;
    }
    return 0;
}
