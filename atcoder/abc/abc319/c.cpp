#include "template.hpp"

int bingo[][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6},
};

int main() {
    int C[9];
    rep (i, 9) cin >> C[i];

    vector<int> P(9);
    iota(all(P), 0);

    int res = 0;
    do {
        bool ok = true;
        bool O[9] = {};
        for (int x: P) {
            O[x] = true;
            rep (i, 8) {
                int idx = -1;
                rep (j, 3) {
                    if (bingo[i][j] == x) idx = j;
                }
                if (idx == -1) continue;

                if (O[bingo[i][0]] and O[bingo[i][1]] and O[bingo[i][2]]) {
                    int j = (idx + 1) % 3;
                    int k = (idx + 2) % 3;
                    if (C[bingo[i][j]] == C[bingo[i][k]] and C[bingo[i][idx]] != C[bingo[i][j]]) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) res++;
    } while (next_permutation(all(P)));

    cout << res / 362880.0 << endl;

    return 0;
}
