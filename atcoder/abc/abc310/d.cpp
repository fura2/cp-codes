#include "template.hpp"

int n, t, m;
bool A[10][10];

int id[10];

int dfs(int i, int cur) {
    if (cur > t) {
        return 0;
    }
    if (i == n) {
        return cur == t ? 1 : 0;
    }
    int res = 0;
    rep(j, cur) {
        id[i] = j;
        bool ok = true;
        rep(k, i) if (id[k] == id[i] && A[k][i]) ok = false;
        if (ok) res += dfs(i + 1, cur);
    }
    id[i] = cur;
    res += dfs(i + 1, cur + 1);
    return res;
}

int main() {
    cin >> n >> t >> m;
    rep(i, m) {
        int u, v; cin >> u >> v; u--; v--;
        A[u][v] = A[v][u] = true;
    }

    cout << dfs(0, 0) << endl;

    return 0;
}
