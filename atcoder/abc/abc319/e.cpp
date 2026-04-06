#include "template.hpp"

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> P(n - 1), T(n - 1);
    rep (i, n - 1) cin >> P[i] >> T[i];

    lint elapsed[840];
    rep (d, 840) {
        lint t = d;
        rep (i, n - 1) {
            t = (t + P[i] - 1) / P[i] * P[i];
            t += T[i];
        }
        elapsed[d] = t - d;
    }

    int q;
    cin >> q;
    rep (q) {
        lint r;
        cin >> r;
        cout << r + x + elapsed[(r + x) % 840] + y << "\n";
    }

    return 0;
}
