#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    vector<int> a(3 * n);
    for (auto& e : a) cin >> e, e--;

    vector<int> cnt(n), ans;
    rep(i, 3 * n) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) ans.emplace_back(a[i]);
    }
    rep(i, n) cout << ans[i] + 1 << " ";

    return 0;
}
