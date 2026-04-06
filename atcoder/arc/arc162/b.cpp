#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

bool solve(vector<int> p) {
    int n = p.size();

    vector<pair<int, int>> ans;
    rep(i, n - 2) {
        if (p[i] == i) continue;

        int pos;
        rep(j, n) if (p[j] == i) pos = j;

        if (pos == n - 1) {
            ans.emplace_back(pos - 2, n - 2);
            int x = p[pos - 2], y = p[pos - 1];
            p.erase(p.begin() + pos - 2, p.begin() + pos);
            p.insert(p.end(), {x, y});
            i--;
        }
        else {
            ans.emplace_back(pos, i);
            int x = p[pos], y = p[pos + 1];
            p.erase(p.begin() + pos, p.begin() + pos + 2);
            p.insert(p.begin() + i, {x, y});
        }
    }

    if (p[n - 2] != n - 2) {
        cout << "No" << endl;
        return false;
    }
    cout << "Yes\n" << ans.size() << "\n";
    for (auto [i, j] : ans) cout << i + 1 << " " << j << "\n";
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i], p[i]--;
    solve(p);

    return 0;
}
