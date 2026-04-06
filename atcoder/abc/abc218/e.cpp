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
    vector<tuple<int, int, long>> E;
    rep(i, m) {
        int u, v;
        long c; cin >> u >> v >> c; u--; v--;
        if (c <= 0) {
            U.unite(u, v);
        }
        else {
            E.emplace_back(u, v, c);
        }
    }
    m = E.size();

    sort(E.begin(), E.end(), [](const auto& e, const auto& f) { return get<2>(e) < get<2>(f); });

    long ans = 0;
    for (const auto& [u, v, wt] : E) {
        if (!U.is_same(u, v)) {
            U.unite(u, v);
        }
        else ans += wt;
    }
    cout << ans << endl;

    return 0;
}
