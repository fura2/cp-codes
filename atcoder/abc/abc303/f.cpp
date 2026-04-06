#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n;
    int64_t h; cin >> n >> h;
    vector<pair<int64_t, int64_t>> a(n); // (turn, damage)
    rep(i, n) cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(),
        [](auto& x, auto& y) { return make_pair(-x.second, -x.first) < make_pair(-y.second, -y.first); });

    vector<int> reps = { 0 }; // representatives
    int64_t y_pre = a[0].first * a[0].second;
    for (int i = 1;i < n;i++) {
        int64_t y = a[i].first * a[i].second;
        if (y_pre < y) {
            reps.emplace_back(i);
            y_pre = y;
        }
    }

    int64_t x = 0;
    rep(i, int(reps.size())) {
        auto [turn, dmg] = a[reps[i]];

        // naname
        if (__int128_t(dmg) * (turn * (turn + 1) / 2 - x * (x + 1) / 2) >= h) {
            int64_t lo = 0, hi = turn;
            while (hi - lo > 1) {
                int64_t mi = (lo + hi) / 2;
                if (__int128_t(dmg) * (mi * (mi + 1) / 2 - x * (x + 1) / 2) >= h) hi = mi;
                else lo = mi;
            }
            x = hi;
            break;
        }
        h -= dmg * (turn * (turn + 1) / 2 - x * (x + 1) / 2);
        x = turn;

        // flat
        int64_t total_dmg = dmg * turn;
        if (i == int(reps.size()) - 1) {
            x += (h + total_dmg - 1) / total_dmg;
            break;
        }
        int64_t dmg_next = a[reps[i + 1]].second;
        int64_t x_next = total_dmg / dmg_next;
        if (__int128_t(total_dmg) * (x_next - x) >= h) {
            x += (h + total_dmg - 1) / total_dmg;
            break;
        }
        h -= total_dmg * (x_next - x);
        x = x_next;
    }
    cout << x << endl;

    return 0;
}
