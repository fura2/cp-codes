#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i], p[i]--;

    int ans = 0;
    rep(i, n) {
        bool ok = true;
        for (int j = i + 1; j < n; j++) if (p[j] < p[i]) ok = false;
        if (ok) ans++;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
