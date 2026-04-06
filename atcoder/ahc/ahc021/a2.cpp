// a smart greedy algorithm

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    const int n = 30;
    const int m = n * (n + 1) / 2;
    int a[n][n];
    rep(i, n) rep(j, i + 1) cin >> a[i][j];

    vector<tuple<int, int, int, int>> ans;
    rep(v, m) {
        int i, j;
        rep(x, n) rep(y, x + 1) if (a[x][y] == v) i = x, j = y;

        while (i > 0) {
            int i2 = i - 1, j2, diff = 0;
            rep(d, 2) {
                if (0 <= j - d && j - d <= i2 && diff < a[i2][j - d] - a[i][j]) {
                    j2 = j - d;
                    diff = a[i2][j2] - a[i][j];
                }
            }
            if (diff == 0) break;

            ans.emplace_back(i, j, i2, j2);
            swap(a[i][j], a[i2][j2]);
            i = i2;
            j = j2;
        }
    }

    cout << ans.size() << endl;
    for (auto [i, j, x, y] : ans) cout << i << " " << j << " " << x << " " << y << endl;

    return 0;
}
