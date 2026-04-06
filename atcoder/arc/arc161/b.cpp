#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define show(v) { cout << "["; bool _b = true; for (const auto& e : v) { cout << (_b ? "" : ", ") << e; _b = false; } cout << "]" << endl; }

using namespace std;

void solve() {
    long long n; cin >> n;
    if (n < 7) {
        cout << "-1\n";
        return;
    }

    int msb = 63 - __builtin_clzll(n);
    long long ans = 7;
    if (msb >= 3) {
        ans = max(ans, (1LL << msb - 1) | (1LL << msb - 2) | (1LL << msb - 3));
    }
    rep(i, msb) rep(j, i) {
        long long tmp = (1LL << msb) | (1LL << i) | (1LL << j);
        if (tmp <= n) ans = max(ans, tmp);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
