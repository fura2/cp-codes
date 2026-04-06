#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using graph = vector<vector<int>>;

void add_directed_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
}

void solve() {
    int n, k; cin >> n >> k;
    graph T(n);
    for (int v = 1; v < n; v++) {
        int u; cin >> u; u--;
        add_directed_edge(T, u, v);
    }
    vector<int> a(n);
    rep(u, n) cin >> a[u];

    rep(u, n) {
        vector<int> hist(n + 2);
        auto dfs = [&](auto&& dfs, int u, int p) -> void {
            hist[a[u] + 1]++;
            for (int v : T[u]) if (v != p) {
                dfs(dfs, v, u);
            }
        };
        dfs(dfs, u, -1);
        if (hist[0] >= 2 || hist[k + 1] > 0) continue;

        int cnt = 0;
        rep(x, k) if (hist[x + 1] > 0) cnt++;
        if ((hist[0] == 0 && cnt == k) || (hist[0] == 1 && cnt >= k - 1)) {
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int t; cin >> t;
    rep(_, t) solve();

    return 0;
}
