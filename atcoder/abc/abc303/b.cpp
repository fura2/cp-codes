#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, m; cin >> n >> m;
    int a[50][50];
    rep(i, m) rep(j, n) cin >> a[i][j], a[i][j]--;

    bool res[50][50] = {};
    rep(i, m) rep(j, n - 1) res[a[i][j]][a[i][j + 1]] = res[a[i][j + 1]][a[i][j]] = true;

    int ans = 0;
    rep(i, n) rep(j, i) if (!res[i][j]) ans++;
    cout << ans << endl;

    return 0;
}
