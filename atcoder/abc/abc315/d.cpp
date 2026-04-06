#include "template.hpp"

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> B(h);
    rep(i, h) cin >> B[i];

    vector<map<char, int>> R(h), C(w);
    rep(i, h) rep(j, w) {
        ++R[i][B[i][j]];
        ++C[j][B[i][j]];
    }

    while (true) {
        bool end = true;
        vector<pair<char, int>> Dr, Dc;
        rep(i, h) if (size(R[i]) == 1 && R[i].begin()->second >= 2) {
            Dr.emplace_back(R[i].begin()->first, i);
            end = false;
        }
        rep(j, w) if (size(C[j]) == 1 && C[j].begin()->second >= 2) {
            Dc.emplace_back(C[j].begin()->first, j);
            end = false;
        }
        if (end)
            break;

        // update
        for (auto [c, i] : Dr) {
            rep(j, w) {
                if (C[j].count(c) > 0 && --C[j][c] == 0) {
                    C[j].erase(c);
                }
            }
        }
        for (auto [c, j] : Dc) {
            rep(i, h) {
                if (R[i].count(c) > 0 && --R[i][c] == 0) {
                    R[i].erase(c);
                }
            }
        }
        for (auto [c, i] : Dr) {
            R[i].clear();
        }
        for (auto [c, j] : Dc) {
            C[j].clear();
        }
    }

    int ans = 0;
    rep(i, h) for (auto [k, v] : R[i]) ans += v;
    cout << ans << endl;

    return 0;
}
