#include "template.hpp"

vector<vector<int>> cycles(const vector<int>& f) {
    int n = f.size();
    vector<vector<int>> res;
    vector<int> color(n, -1);
    rep(u, n) if (color[u] == -1) {
        int v = u;
        do { color[v] = u; v = f[v]; } while (color[v] == -1);
        if (color[v] == u) {
            vector<int> C;
            int w = v;
            do { C.emplace_back(v); v = f[v]; } while (v != w);
            res.emplace_back(C);
        }
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> to(n);
    rep(u, n) cin >> to[u], to[u]--;

    auto C = cycles(to)[0];
    cout << ssize(C) << endl;
    for (int u : C) cout << u + 1 << " ";

    return 0;
}
