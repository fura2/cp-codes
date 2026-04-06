#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

class union_find {
    int n;
    vector<int> p;
public:
    union_find(int n = 0) { build(n); }
    void build(int n) {
        this->n = n;
        p.assign(n, -1);
    }
    int find(int u) { return p[u] < 0 ? u : p[u] = find(p[u]); }
    void unite(int u, int v) {
        u = find(u); v = find(v);
        if (u != v) {
            if (p[v] < p[u]) swap(u, v);
            p[u] += p[v]; p[v] = u; n--;
        }
    }
    bool is_same(int u, int v) { return find(u) == find(v); }
    int size()const { return n; }
    int size(int u) { return -p[find(u)]; }
};

void dfs(int u, int p, int dep, const graph& T, graph& T2) {
    for (int v : T[u]) if (v != p) {
        if (dep % 3 != 2) {
            add_undirected_edge(T2, u, v);
        }
        dfs(v, u, dep + 1, T, T2);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    graph T(n), T2(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v; u--; v--;
        add_undirected_edge(T, u, v);
    }

    int root = -1;
    rep(u, n) if (T[u].size() == 1) root = u;

    dfs(root, -1, 0, T, T2);

    union_find U(n);
    rep(u, n) for (int v : T2[u]) if (u < v) U.unite(u, v);

    map<int, int> hist;
    rep(u, n) hist[U.find(u)]++;
    vector<int> ans;
    for (auto [k, v] : hist) ans.emplace_back(v - 1);
    sort(ans.begin(), ans.end());
    for (int v : ans) cout << v << " ";

    return 0;
}
