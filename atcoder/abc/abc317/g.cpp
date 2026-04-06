#include "template.hpp"

class bipartite_graph {
    int L, R;
    vector<vector<int>> G, match;
    vector<bool> vis;

    bool augment(int u) {
        if (u == -1) return true;
        for (int v: G[u])
            if (!vis[v]) {
                vis[v] = true;
                if (augment(match[1][v])) {
                    match[0][u] = v;
                    match[1][v] = u;
                    return true;
                }
            }
        return false;
    }

  public:
    bipartite_graph(int L, int R): L(L), R(R), G(L) {}

    void add_edge(int u, int v) {
        G[u].emplace_back(v);
    }

    const vector<int>& operator[](int u) const {
        return G[u];
    }

    pair<int, vector<vector<int>>> bipartite_matching() {
        match.resize(2);
        match[0].assign(L, -1);
        match[1].assign(R, -1);

        int res = 0;
        vis.resize(R);
        rep (u, L) {
            fill(vis.begin(), vis.end(), false);
            if (augment(u)) res++;
        }

        return {res, match};
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector A(n, vector<int>(m));
    rep (i, n) {
        rep (j, m) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    vector Ans(n, vector(m, -1));
    rep (j, m) { // 1 列ずつ決めていく
        bipartite_graph G(n, n); // row -> value v
        rep (i, n) {
            rep (k, m) {
                if (A[i][k] != -1) {
                    G.add_edge(i, A[i][k]);
                }
            }
        }

        auto match = G.bipartite_matching().second[0];
        rep (i, n) {
            int val = match[i];
            Ans[i][j] = val;
            rep (k, m) {
                if (A[i][k] == val) {
                    A[i][k] = -1;
                    break;
                }
            }
        }
    }

    yes();
    rep (i, n) {
        rep (j, m) {
            cout << Ans[i][j] + 1 << " \n"[j < m - 1 ? 0 : 1];
        }
    }

    return 0;
}
