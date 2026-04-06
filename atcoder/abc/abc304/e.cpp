#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

class union_find {
    int n;
    vector<int> p;
public:
    union_find(int n = 0) { build(n); }
    void build(int n) {
        this->n = n;
        p.assign(n, -1);
    }
    int find(int u) { return p[u] < 0 ? u : p[u] = find(p[u]); }
    void unite(int u, int v) {
        u = find(u); v = find(v);
        if (u != v) {
            if (p[v] < p[u]) swap(u, v);
            p[u] += p[v]; p[v] = u; n--;
        }
    }
    bool is_same(int u, int v) { return find(u) == find(v); }
    int size()const { return n; }
    int size(int u) { return -p[find(u)]; }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, m; cin >> n >> m;
    union_find U(n);
    rep(i, m) {
        int u, v; cin >> u >> v; u--; v--;
        U.unite(u, v);
    }

    set<pair<int, int>> bad;
    int k; cin >> k;
    rep(i, k) {
        int x, y; cin >> x >> y; x--; y--;
        x = U.find(x);
        y = U.find(y);
        if (x > y) swap(x, y);
        bad.emplace(x, y);
    }

    int q; cin >> q;
    rep(_, q) {
        int x, y; cin >> x >> y; x--; y--;
        x = U.find(x);
        y = U.find(y);
        if (x > y) swap(x, y);
        cout << (bad.count({ x,y }) ? "No" : "Yes") << "\n";
    }

    return 0;
}
