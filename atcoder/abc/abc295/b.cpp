#include "template.hpp"

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> B(h);
    rep(i, h) cin >> B[i];

    auto C = B;
    rep(i, h) rep(j, w) if (isdigit(B[i][j])) {
        rep(x, h) rep(y, w) if (abs(i - x) + abs(j - y) <= B[i][j] - '0') C[x][y] = '.';
    }
    rep(i, h) cout << C[i] << endl;

    return 0;
}
