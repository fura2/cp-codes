#include "template.hpp"

class mint {
    static const int MOD = 998244353;
    int x;

  public:
    mint() : x(0) {}
    mint(long long y) {
        x = y % MOD;
        if (x < 0)
            x += MOD;
    }

    mint &operator+=(const mint &m) {
        x += m.x;
        if (x >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator-=(const mint &m) {
        x -= m.x;
        if (x < 0)
            x += MOD;
        return *this;
    }
    mint &operator*=(const mint &m) {
        x = (long long)x * m.x % MOD;
        return *this;
    }
    mint &operator/=(const mint &m) { return *this *= inverse(m); }
    mint operator+(const mint &m) const { return mint(*this) += m; }
    mint operator-(const mint &m) const { return mint(*this) -= m; }
    mint operator*(const mint &m) const { return mint(*this) *= m; }
    mint operator/(const mint &m) const { return mint(*this) /= m; }
    mint operator-() const { return -x; }

    friend mint inverse(const mint &m) {
        int a = m.x, b = MOD, u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return u;
    }

    friend istream &operator>>(istream &is, mint &m) {
        long long t;
        is >> t;
        m = t;
        return is;
    }
    friend ostream &operator<<(ostream &os, const mint &m) { return os << m.x; }
    int to_int() const { return x; }
};

mint operator+(long long x, const mint &m) { return mint(x) + m; }
mint operator-(long long x, const mint &m) { return mint(x) - m; }
mint operator*(long long x, const mint &m) { return mint(x) * m; }
mint operator/(long long x, const mint &m) { return mint(x) / m; }

using graph = vector<vector<int>>;

void add_directed_edge(graph &G, int u, int v) {
    G[u].emplace_back(v);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> P(n - 1);
    for (auto &[u, v] : P) {
        cin >> u >> v;
        u--;
        v--;
    }

    vector<int> par(2 * n - 1, -1);
    auto find = [&](auto &&find, int u) -> int {
        if (par[u] == -1)
            return u;
        return par[u] = find(find, par[u]);
    };

    graph T(2 * n - 1);
    rep(i, n - 1) {
        auto [u, v] = P[i];
        u = find(find, u);
        v = find(find, v);
        int w = n + i;
        par[u] = par[v] = w;
        add_directed_edge(T, w, u);
        add_directed_edge(T, w, v);
    }
    int root = 2 * n - 2;

    vector<int> sz(2 * n - 1); // sz[u] = (number of leaves in the subtree rooted at u)
    rep(u, n) sz[u] = 1;
    auto dfs1 = [&](auto &&dfs, int u) -> void {
        for (int v : T[u]) {
            dfs(dfs, v);
            sz[u] += sz[v];
        }
    };
    dfs1(dfs1, root);

    vector<mint> ans(n);
    auto dfs2 = [&](auto &&dfs, int u, mint cum) -> void {
        if (u < n) {
            ans[u] = cum;
        }
        for (int v : T[u]) {
            dfs(dfs, v, cum + mint(sz[v]) / sz[u]);
        }
    };
    dfs2(dfs2, root, 0);

    rep(u, n) cout << ans[u] << " \n"[u < n - 1 ? 0 : 1];

    return 0;
}
