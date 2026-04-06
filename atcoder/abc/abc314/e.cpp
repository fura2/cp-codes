#include "template.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> C(n);
    vector<vector<int>> A(n);
    rep(i, n) {
        int k;
        cin >> C[i] >> k;
        A[i].resize(k);
        rep(j, k) cin >> A[i][j];
    }

    vector<double> ex(m + 1, 1e60);
    ex[m] = 0;
    rrep(x, m) {
        rep(i, n) {
            int k = size(A[i]);
            double val = 0;
            int n0 = 0;
            rep(j, k) {
                if (A[i][j] == 0)
                    n0++;
                else
                    val += ex[min(x + A[i][j], m)];
            }
            chmin(ex[x], (C[i] + val / k) * k / (k - n0));
        }
    }
    cout << ex[0] << endl;

    return 0;
}
