#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

pair<int, int> solve(vector<int> ys, const vector<int>& b) {
    int n = ys.size();
    sort(ys.begin(), ys.end());

    int mn = n, mx = 0, cnt = 0;
    int idx_prev = -1;
    rep(i, n) {
        int y = ys[i];
        int idx = lower_bound(b.begin(), b.end(), y) - b.begin();
        if (idx_prev + 1 < idx) mn = 0;
        idx_prev = idx;
        cnt++;

        if (i == n - 1 || b[idx] < ys[i + 1]) {
            mn = min(mn, cnt);
            mx = max(mx, cnt);
            cnt = 0;
        }
    }
    if (idx_prev + 1 < b.size()) mn = 0;

    return { mn, mx };
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int w, h, n; cin >> w >> h >> n;
    vector<pair<int, int>> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second;
    int na; cin >> na;
    vector<int> a(na);
    rep(i, na) cin >> a[i];
    int nb; cin >> nb;
    vector<int> b(nb);
    rep(i, nb) cin >> b[i];

    a.push_back(w);
    b.push_back(h);

    sort(p.begin(), p.end());

    int mn = n, mx = 0;
    int idx_prev = -1;
    vector<int> ys;
    rep(i, n) {
        auto [x, y] = p[i];
        int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (idx_prev + 1 < idx) mn = 0;
        idx_prev = idx;
        ys.push_back(y);

        if (i == n - 1 || a[idx] < p[i + 1].first) {
            auto [tmp_mn, tmp_mx] = solve(ys, b);
            mn = min(mn, tmp_mn);
            mx = max(mx, tmp_mx);
            ys.clear();
        }
    }
    if (idx_prev + 1 < a.size()) mn = 0;

    cout << mn << " " << mx << "\n";

    return 0;
}
