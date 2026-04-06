#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define show(v) { cout << "["; bool _b = true; for (const auto& e : v) { cout << (_b ? "" : ", ") << e; _b = false; } cout << "]" << endl; }

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    auto b = a;
    rep(i, n / 2) {
        b[2 * i] = a[i];
        b[2 * i + 1] = a[n / 2 + i + 1];
    }
    b[n - 1] = a[n / 2];

    bool ok = true;
    rep(i, n - 1) {
        if (i % 2 == 0 && b[i] >= b[i + 1]) ok = false;
        if (i % 2 == 1 && b[i] <= b[i + 1]) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
