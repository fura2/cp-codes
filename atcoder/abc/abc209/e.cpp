#include "template.hpp"

using graph = vector<vector<int>>;

void add_directed_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
}

int to_index(string s) {
    int res = 0;
    rep(i, 3) {
        res *= 52;
        if (isupper(s[i])) res += s[i] - 'A';
        else res += s[i] - 'a' + 26;
    }
    return res;
}

int main() {
    int m; cin >> m;
    vector<string> S(m);

    int n = 52 * 52 * 52;
    graph G(n);
    rep(i, m) {
        cin >> S[i];
        int u = to_index(S[i].substr(0, 3));
        int v = to_index(S[i].substr(size(S[i]) - 3));
        add_directed_edge(G, v, u); // 逆向きに辺を張る
    }

    vector<int> deg(n); // indegree of G
    rep(u, n) for (int v : G[u]) deg[v]++;

    // label[u] = 0 if 手番を持つプレイヤーの勝ち
    //            1 if 手番を持つプレイヤーの負け
    //            2 if 引き分け
    // v へのすべての有向辺 u->v について label[u] == 0 なら, label[v] = 1
    // v へのある有向辺 u->v について label[u] == 1 なら, lavel[v] = 0
    // これらの規則を繰り返し適用して確定しないなら label[v] = 2
    vector<int> label(n, 2);

    queue<int> Q;
    rep(u, n) if (deg[u] == 0) {
        Q.emplace(u);
        label[u] = 1;
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (label[u] == 0) {
            for (int v : G[u]) {
                if (label[v] == 2) {
                    deg[v]--;
                    if (deg[v] == 0) {
                        label[v] = 1;
                        Q.emplace(v);
                    }
                }
            }
        }
        else if (label[u] == 1) {
            for (int v : G[u]) {
                if (label[v] == 2) {
                    deg[v]--;
                    label[v] = 0;
                    Q.emplace(v);
                }
            }
        }
    }

    rep(i, m) {
        int u = to_index(S[i].substr(size(S[i]) - 3));
        cout << vector{ "Aoki", "Takahashi", "Draw" } [label[u]] << "\n";
    }

    return 0;
}
