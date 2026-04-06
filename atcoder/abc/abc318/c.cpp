#include "template.hpp"

int main() {
    lint n, d, p;
    cin >> n >> d >> p;

    vector<lint> F(n);
    rep (i, n) cin >> F[i];
    sort(all(F));

    lint ans = (n + d - 1) / d * p, cum = 0;
    rep (i, n) {
        cum += F[i];
        chmin(ans, cum + (n - (i + 1) + d - 1) / d * p);
    }
    cout << ans << endl;

    return 0;
}
