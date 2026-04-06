#include "template.hpp"

int main() {
    int n; cin >> n;
    vector A(n, vector(n, 0)), B(n, vector(n, 0));
    rep(i, n) rep(j, n) cin >> A[i][j];
    rep(i, n) rep(j, n) cin >> B[i][j];

    rep(4) {
        bool ok = true;
        rep(i, n) rep(j, n) if (A[i][j] == 1 && B[i][j] == 0) ok = false;
        if (ok) {
            yes();
            return 0;
        }
        auto A2 = A;
        rep(i, n) rep(j, n) A2[i][j] = A[n - j - 1][i];
        A = A2;
    }
    no();

    return 0;
}
