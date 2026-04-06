#include "template.hpp"

const int INF = 1 << 29;

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

class mint {
    static const int MOD = 998244353;
    int x;

  public:
    mint(): x(0) {}
    mint(long long y) {
        x = y % MOD;
        if (x < 0) x += MOD;
    }

    mint& operator+=(const mint& m) {
        x += m.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& m) {
        x -= m.x;
        if (x < 0) x += MOD;
        return *this;
    }
    mint& operator*=(const mint& m) {
        x = (long long)x * m.x % MOD;
        return *this;
    }
    mint& operator/=(const mint& m) {
        return *this *= inverse(m);
    }
    mint operator+(const mint& m) const {
        return mint(*this) += m;
    }
    mint operator-(const mint& m) const {
        return mint(*this) -= m;
    }
    mint operator*(const mint& m) const {
        return mint(*this) *= m;
    }
    mint operator/(const mint& m) const {
        return mint(*this) /= m;
    }
    mint operator-() const {
        return -x;
    }

    friend mint inverse(const mint& m) {
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

    friend istream& operator>>(istream& is, mint& m) {
        long long t;
        is >> t;
        m = t;
        return is;
    }
    friend ostream& operator<<(ostream& os, const mint& m) {
        return os << m.x;
    }
    int to_int() const {
        return x;
    }
};

mint operator+(long long x, const mint& m) {
    return mint(x) + m;
}
mint operator-(long long x, const mint& m) {
    return mint(x) - m;
}
mint operator*(long long x, const mint& m) {
    return mint(x) * m;
}
mint operator/(long long x, const mint& m) {
    return mint(x) / m;
}

int main() {
    int n, m;
    cin >> n >> m;
    graph G(n);
    set<pair<int, int>> E;
    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v) swap(u, v);
        add_undirected_edge(G, u, v);
        E.emplace(u, v);
    }

    set<int> V; // not visited veritices
    rep (u, n) V.emplace(u);
    vector<int> D(n, INF);
    queue<int> Q;
    V.erase(0);
    D[0] = 0;
    Q.emplace(0);
    while (not Q.empty()) {
        int u = Q.front();
        Q.pop();
        vector<int> dels;
        for (int v: V) {
            auto [x, y] = minmax(u, v);
            if (D[v] != INF or E.count({x, y}) > 0) continue;

            dels.emplace_back(v);
            D[v] = D[u] + 1;
            Q.emplace(v);
        }
        for (int v: dels) V.erase(v);
    }

    if (D[n - 1] == INF) {
        cout << -1 << endl;
        return 0;
    }

    // topological order
    vector<int> P(n);
    iota(all(P), 0);
    sort(all(P), [&](int u, int v) { return make_pair(D[u], u) < make_pair(D[v], v); });

    vector<int> inv(n);
    rep (i, n) inv[P[i]] = i;

    vector<pair<int, int>> range(n, {INF, -INF});
    rep (i, n) {
        int u = P[i];
        if (D[u] == INF) continue;
        chmin(range[D[u]].first, i);
        chmax(range[D[u]].second, i + 1);
    }
    vector<mint> dp(n), dp_cum(n + 1);
    dp[0] = 1;
    dp_cum[1] = 1;
    rep (i, n) {
        int u = P[i];
        if (D[u] == 0 or D[u] == INF) continue;

        auto [l, r] = range[D[u] - 1];
        if (l == INF) continue;

        mint res = dp_cum[r] - dp_cum[l];
        for (int v: G[u]) {
            if (D[v] + 1 == D[u]) {
                res -= dp[inv[v]];
            }
        }
        dp[i] = res;
        dp_cum[i + 1] = dp_cum[i] + dp[i];
    }
    cout << dp[inv[n - 1]] << endl;

    return 0;
}
