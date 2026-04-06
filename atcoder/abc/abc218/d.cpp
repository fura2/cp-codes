#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    set<pair<int, int>> S;
    rep(i, n) S.emplace(x[i], y[i]);

    int ans = 0;
    rep(i, n) rep(j, n) if (x[i] < x[j] && y[i] < y[j]) {
        if (S.count({ x[i], y[j] }) > 0 && S.count({ x[j], y[i] }) > 0) ans++;
    }
    cout << ans << endl;

    return 0;
}
