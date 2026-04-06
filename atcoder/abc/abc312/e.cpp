#include "template.hpp"

struct Cuboid {
    int x1, x2, y1, y2, z1, z2;

    void rot() {
        int t1 = x1, t2 = x2;
        x1 = y1;
        x2 = y2;
        y1 = z1;
        y2 = z2;
        z1 = t1;
        z2 = t2;
    }
};

int main() {
    int n; cin >> n;
    vector<Cuboid> C(n);
    rep(i, n) cin >> C[i].x1 >> C[i].y1 >> C[i].z1 >> C[i].x2 >> C[i].y2 >> C[i].z2;

    vector<int> ans(n);
    rep(3) {
        vector IdxL(101, vector<int>());
        vector IdxR(101, vector<int>());
        rep(i, n) IdxL[C[i].x1].emplace_back(i);
        rep(i, n) IdxR[C[i].x2].emplace_back(i);

        int L[101][101], R[101][101];
        rep(t, 1, 100) {
            memset(L, 0, sizeof L);
            memset(R, 0, sizeof R);

            for (int i : IdxL[t]) {
                L[C[i].y1][C[i].z1] += i + 1;
                L[C[i].y1][C[i].z2] -= i + 1;
                L[C[i].y2][C[i].z1] -= i + 1;
                L[C[i].y2][C[i].z2] += i + 1;
            }
            for (int i : IdxR[t]) {
                R[C[i].y1][C[i].z1] += i + 1;
                R[C[i].y1][C[i].z2] -= i + 1;
                R[C[i].y2][C[i].z1] -= i + 1;
                R[C[i].y2][C[i].z2] += i + 1;
            }
            rep(y, 100) rep(z, 101) {
                L[y + 1][z] += L[y][z];
                R[y + 1][z] += R[y][z];
            }
            rep(z, 100) rep(y, 101) {
                L[y][z + 1] += L[y][z];
                R[y][z + 1] += R[y][z];
            }

            set<pair<int, int>> used;
            rep(y, 101) rep(z, 101) {
                if (L[y][z] != 0 && R[y][z] != 0) {
                    int i = L[y][z] - 1;
                    int j = R[y][z] - 1;
                    if (i > j) swap(i, j);
                    if (used.count({ i, j }) == 0) {
                        used.emplace(i, j);
                        ans[i]++;
                        ans[j]++;
                    }
                }
            }
        }

        rep(i, n) C[i].rot();
    }

    rep(i, n) cout << ans[i] << "\n";

    return 0;
}
