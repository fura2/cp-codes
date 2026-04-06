#include "template.hpp"

const lint INF = 1LL << 61;

int main() {
    lint n, m; cin >> n >> m;

    lint ans = INF;
    for (lint a = 1; (a - 1) * (a - 1) <= m; a++) {
        lint b = (m + a - 1) / a;
        if (a <= n && b <= n) {
            chmin(ans, a * b);
        }
    }
    cout << (ans < INF ? ans : -1) << endl;

    return 0;
}
