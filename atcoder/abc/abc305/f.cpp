#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using graph = vector<vector<int>>;

void add_directed_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
}

int n, m;
bool vis[100];
graph G;

bool dfs(int u) {
    if (u == n - 1) {
        string s; cin >> s;
        assert(s == "OK");
        return true;
    }

    vis[u] = true;

    for (int v : G[u]) if (!vis[v]) {
        cout << v + 1 << endl;
        if (v != n - 1) {
            int k; cin >> k;
            rep(i, k) {
                int w; cin >> w; w--;
                add_directed_edge(G, v, w);
            }
        }
        if (dfs(v)) return true;

        cout << u + 1 << endl;
        int dummy1, dummy2; cin >> dummy1;
        rep(i, dummy1) cin >> dummy2;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    cin >> n >> m;
    G = graph(n);
    int k; cin >> k;
    rep(i, k) {
        int v; cin >> v; v--;
        add_directed_edge(G, 0, v);
    }

    dfs(0);

    return 0;
}
