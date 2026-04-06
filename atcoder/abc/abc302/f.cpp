#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge {
    int to;
    T wt;
    edge(int to, const T& wt):to(to), wt(wt) {}
};
template<class T> using weighted_graph = vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
    G[v].emplace_back(u, wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G, int s) {
    constexpr T INF = numeric_limits<T>::max();

    int n = G.size();
    vector<T> d(n, INF); d[s] = T{};
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> Q;
    Q.emplace(T{}, s);
    while (!Q.empty()) {
        T d0;
        int u; tie(d0, u) = Q.top();
        Q.pop();
        if (d0 > d[u]) continue;
        for (const auto& [v, wt] : G[u]) {
            if (d[v] > d[u] + wt) {
                d[v] = d[u] + wt;
                Q.emplace(d[v], v);
            }
        }
    }
    return d;
}

int main() {
    int n, m; cin >> n >> m;
    vector a(n, vector<int>());
    rep(i, n) {
        int sz; cin >> sz;
        a[i].resize(sz);
        rep(j, sz) cin >> a[i][j], a[i][j]--;
    }

    vector<int> offset(n + 1);
    vector idxs(m, vector<int>());
    rep(i, n) {
        offset[i + 1] = offset[i] + a[i].size();
        rep(j, a[i].size()) {
            idxs[a[i][j]].push_back(offset[i] + j);
        }
    }

    int N = offset[n] + m;
    weighted_graph<int> G(N);
    rep(i, n) {
        rep(j, int(a[i].size()) - 1) {
            add_undirected_edge(G, offset[i] + j, offset[i] + j + 1, 0);
        }
    }
    rep(x, m) {
        rep(i, idxs[x].size()) {
            add_undirected_edge(G, idxs[x][i], offset[n] + x, 1);
        }
    }

    auto res = Dijkstra(G, offset[n])[N - 1];
    if (res < INT_MAX) {
        cout << (res - 2) / 2 << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
