#include "template.hpp"

int main() {
    string B[8];
    rep(i, 8) cin >> B[i];

    rep(i, 8) rep(j, 8) if (B[i][j] == '*') cout << "abcdefgh"[j] << 8 - i << endl;

    return 0;
}
