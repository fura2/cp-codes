#include "template.hpp"

int main() {
    int n, m; cin >> n >> m;
    vector<int> p(n);
    vector f(n, vector<int>());
    rep(i, n) {
        int k; cin >> p[i] >> k;
        f[i].resize(k);
        rep(j, k) cin >> f[i][j];
        sort(all(f[i]));
    }

    rep(i, n) rep(j, n) {
        if (p[i] <= p[j] && includes(all(f[i]), all(f[j]))) {
            if (p[i] < p[j] || f[i].size() > f[j].size()) {
                yes();
                return 0;
            }
        }
    }
    no();

    return 0;
}
