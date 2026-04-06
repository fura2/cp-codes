#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, q; cin >> n >> q;

    vector<int> deg(n);
    set<pair<int, int>> E;

    int ans = n;
    rep(_, q) {
        int id; cin >> id;
        if (id == 1) {
            int u, v; cin >> u >> v; u--; v--;
            if (deg[u] == 0) ans--;
            if (deg[v] == 0) ans--;
            deg[u]++;
            deg[v]++;
            E.insert({ u, v });
            E.insert({ v, u });
        }
        else {
            int u; cin >> u; u--;
            if (deg[u] > 0) ans++;
            deg[u] = 0;
            vector<int> vs;
            for (auto it = E.lower_bound({ u, 0 });;++it) {
                if (it == E.end() || it->first != u) break;
                int v = it->second;
                deg[v]--;
                if (deg[v] == 0) ans++;
                vs.emplace_back(v);
            }
            for (int v : vs) {
                E.erase({ u, v });
                E.erase({ v, u });
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
