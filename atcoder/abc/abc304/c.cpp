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

    int n, d; cin >> n >> d;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    union_find U(n);
    rep(i, n) rep(j, n) if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= d * d) {
        U.unite(i, j);
    }

    rep(i, n) cout << (U.is_same(0, i) ? "Yes" : "No") << '\n';

    return 0;
}
