#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define show(x) { std::cout << #x << " = " << x << endl; }

void yes(bool b) {
    std::cout << (b ? "Yes" : "No") << "\n";
}

template<class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        std::cout << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        std::cout << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e : v) {
        if (!first) os << ", ";
        first = false;
        std::cout << e;
    }
    os << "]";
    return os;
}

using namespace std;

using graph = vector<vector<int>>;

void add_directed_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
}

template<class T>
class strongly_connected_components { strongly_connected_components(const T&) = delete; };

template<>
class strongly_connected_components<graph> {
    vector<int> id;
    vector<vector<int>> Comp;
    graph D;

public:
    strongly_connected_components(const graph& G = {}) { build(G); }

    void build(const graph& G) {
        int n = G.size();
        graph G_rev(n);
        rep(u, n) for (int v : G[u]) add_directed_edge(G_rev, v, u);

        int k;
        vector<int> top(n);

        auto dfs1 = [&](auto&& dfs1, int u)->void {
            id[u] = 0;
            for (int v : G[u]) if (id[v] == -1) dfs1(dfs1, v);
            top[k++] = u;
        };
        auto dfs2 = [&](auto&& dfs2, int u)->void {
            id[u] = k;
            for (int v : G_rev[u]) if (id[v] == -1) dfs2(dfs2, v);
        };

        k = 0;
        id.assign(n, -1);
        rep(u, n) if (id[u] == -1) dfs1(dfs1, u);

        reverse(top.begin(), top.end());

        k = 0;
        id.assign(n, -1);
        for (int u : top) if (id[u] == -1) dfs2(dfs2, u), k++;

        Comp.resize(k);
        D.resize(k);
        rep(u, n) {
            Comp[id[u]].emplace_back(u);
            for (int v : G[u]) if (id[u] != id[v]) add_directed_edge(D, id[u], id[v]);
        }
    }

    int operator[](int u)const { return id[u]; }

    const vector<int>& component(int i)const { return Comp[i]; }
    const graph& DAG()const { return D; }
};

void solve() {
    int n, m; cin >> n >> m;
    graph G(n);
    vector<pair<int, int>> E(m);
    rep(i, m) {
        int u, v; cin >> u >> v; u--; v--;
        add_directed_edge(G, u, v);
        E[i] = {u, v};
    }

    strongly_connected_components SCC(G);
    unordered_set<int> V;
    rep(u, n) if (SCC[u] == SCC[0]) V.emplace(u);
    if (V.size() == 1) {
        cout << "No\n";
        return;
    }

    graph H(n);
    for (auto [u, v] : E) {
        if (V.count(u) && V.count(v)) {
            add_directed_edge(H, u, v);
        }
    }

    vector<int> dep(n, -1);
    dep[0] = 0;
    auto dfs = [&](auto&& self, int u, int p) -> void {
        for (int v : H[u]) if (v != p && dep[v] == -1) {
            dep[v] = dep[u] + 1;
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);

    int g = 0;
    rep(u, n) for (int v : H[u]) {
        g = gcd(g, (dep[u] + 1) - dep[v]);
    }
    while (g % 2 == 0) g /= 2;
    while (g % 5 == 0) g /= 5;
    yes(g == 1);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int t; cin >> t;
    rep(_, t) solve();

    return 0;
}
