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
    vector<int> f(n);
    rep(i, n) cin >> f[i], f[i]--;

    int ans = 0;
    for (const auto& C : cycles(f)) {
        ans += C.size();
    }
    cout << ans << endl;

    return 0;
}
