#include "template.hpp"

int main() {
    int n, m; cin >> n >> m;
    vector<int> p(n);
    vector f(n, vector<int>());
    rep(i, n) {
        int k; cin >> p[i] >> k;
        f[i].resize(k);
        rep(j, k) cin >> f[i][j];
    }

    rep(i, n) rep(j, n) {
        bool b = true;
        for (auto x : f[j]) if (count(all(f[i]), x) == 0) b = false;
        if (p[i] <= p[j] && b) {
            if (p[i] < p[j] || f[i].size() > f[j].size()) {
                yes();
                return 0;
            }
        }
    }
    no();

    return 0;
}
