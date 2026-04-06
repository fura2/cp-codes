#include "template.hpp"

int main() {
    vector<string> code = {
        "###.?????",
        "###.?????",
        "###.?????",
        "....?????",
        "?????????",
        "?????....",
        "?????.###",
        "?????.###",
        "?????.###" };

    int h, w; cin >> h >> w;
    vector<string> B(h);
    rep(i, h) cin >> B[i];

    rep(i, h - 8) rep(j, w - 8) {
        bool ok = true;
        rep(x, 9) rep(y, 9) if (!(code[x][y] == '?' || code[x][y] == B[i + x][j + y])) ok = false;
        if (ok) cout << i + 1 << " " << j + 1 << "\n";
    }

    return 0;
}
