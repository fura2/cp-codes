#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int n;
vector<int> a, cum;

int f(int x) {
    int i = lower_bound(a.begin(), a.end(), x) - a.begin();
    if (i == 0) return 0;
    if (i % 2 == 0) return cum[i - 1] + x - a[i - 1];
    else return cum[i];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    cum.assign(n, 0);
    rep(i, n - 1) cum[i + 1] = cum[i] + (i % 2 == 1 ? a[i + 1] - a[i] : 0);

    int q; cin >> q;
    rep(_, q) {
        int l, r; cin >> l >> r;
        cout << f(r) - f(l) << "\n";
    }

    return 0;
}
