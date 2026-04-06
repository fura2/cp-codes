#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

#define show(v) { cout << "["; bool _b = true; for (const auto& e: v) { cout << (_b ? "" : ", ") << e; _b = false; } cout << "]" << endl; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n;
    int64_t m, k;
    string s; cin >> n >> m >> k >> s;

    vector<int> L; // consecutive 'o's
    for (int i = 0, pre = 0; i <= n; i++) {
        if (i == n || s[i] == 'x') {
            L.emplace_back(i - pre);
            pre = i + 1;
        }
    }
    int64_t nx = L.size() - 1; // number of 'x's

    vector<int64_t> lcum(L.size() + 1), rcum(L.size() + 1);
    rep(i, int(L.size())) {
        lcum[i + 1] = lcum[i] + L[i];
        rcum[L.size() - i - 1] = rcum[L.size() - i] + L[L.size() - i - 1];
    }

    int64_t ans = 0;
    rep(i, int(L.size()) - k) ans = max(ans, k + lcum[i + k + 1] - lcum[i]); // substring of s
    if (m >= 2) {
        rep(i, int(L.size()) + 1) {
            int64_t nl = L.size() - i - 1;
            if (nl > k) continue;
            int64_t n_rep = (k - nl) / nx;
            if (1 + n_rep == m) { // (suffix of s) + (s * n_rep)
                ans = max(ans, k + rcum[i] + (n_rep * (n - nx)));
            }
            else if (1 + n_rep + 1 <= m) { // (suffix of s) + (s * n_rep) + (prefix of s)
                ans = max(ans, k + rcum[i] + (n_rep * (n - nx)) + lcum[(k - nl) % nx + 1]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
