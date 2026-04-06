#include "template.hpp"

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

int main() {
    int n, m;
    cin >> n >> m;
    weighted_graph<pair<lint, lint>> G(n);
    rep (i, m) {
        int u, v;
        lint x, y;
        cin >> u >> v >> x >> y;
        u--;
        v--;
        add_directed_edge(G, u, v, {x, y});
        add_directed_edge(G, v, u, {-x, -y});
    }

    vector<bool> vis(n);
    vector<pair<lint, lint>> pos(n);
    queue<int> Q;
    vis[0] = true;
    pos[0] = {0, 0};
    Q.emplace(0);
    while (not Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto e: G[u]) {
            if (vis[e.to]) continue;
            vis[e.to] = true;
            pos[e.to] = {pos[u].first + e.wt.first, pos[u].second + e.wt.second};
            Q.emplace(e.to);
        }
    }

    rep (u, n) {
        if (not vis[u]) {
            cout << "undecidable" << endl;
        }
        else {
            cout << pos[u].first << " " << pos[u].second << "\n";
        }
    }

    return 0;
}
