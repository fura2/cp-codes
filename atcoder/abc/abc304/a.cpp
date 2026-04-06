#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    vector<string> s(n);
    vector<int> a(n);
    rep(i, n) cin >> s[i] >> a[i];

    int i0 = min_element(a.begin(), a.end()) - a.begin();
    rep(i, n) cout << s[(i0 + i) % n] << '\n';

    return 0;
}
