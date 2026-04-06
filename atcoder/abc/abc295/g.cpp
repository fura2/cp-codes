#include "template.hpp"

// Union-Find, path compression only
// representative is always the node with minimum index
class union_find {
    int n;
    vector<int> p;

  public:
    union_find(int n = 0) {
        build(n);
    }
    void build(int n) {
        this->n = n;
        p.assign(n, -1);
    }
    int find(int u) {
        return p[u] < 0 ? u : p[u] = find(p[u]);
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (v < u) swap(u, v);
            p[u] += p[v];
            p[v] = u;
            n--;
        }
    }
    bool is_same(int u, int v) {
        return find(u) == find(v);
    }
    int size() const {
        return n;
    }
    int size(int u) {
        return -p[find(u)];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> par(n, -1);
    rep (i, n - 1) {
        int p, u = i + 1;
        cin >> p;
        p--;
        par[u] = p;
    }

    int q;
    cin >> q;
    union_find U(n); // 強連結成分たち
    rep (q) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            u = U.find(u);
            v = U.find(v);
            while (u != v) {
                U.unite(u, par[u]);
                u = par[u];
                u = U.find(u);
            }
        }
        else {
            int u;
            cin >> u;
            u--;
            cout << U.find(u) + 1 << "\n";
        }
    }

    return 0;
}
