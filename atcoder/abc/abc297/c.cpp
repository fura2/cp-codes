#include "template.hpp"

int main() {
    int h, w; cin >> h >> w;
    vector<string> B(h);
    rep(i, h) cin >> B[i];

    rep(i, h) rep(j, w - 1) if (B[i][j] == 'T' && B[i][j + 1] == 'T') {
        B[i][j] = 'P';
        B[i][j + 1] = 'C';
    }

    rep(i, h) cout << B[i] << endl;

    return 0;
}
