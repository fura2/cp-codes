#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, m, h, k; cin >> n >> m >> h >> k;
    string s; cin >> s;
    set<pair<int, int>> S;
    rep(i, m) {
        int x, y; cin >> x >> y;
        S.emplace(x, y);
    }

    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'R') x++;
        else if (c == 'L') x--;
        else if (c == 'U') y++;
        else if (c == 'D') y--;
        h--;
        if (h < 0) {
            cout << "No" << endl;
            return 0;
        }
        if (S.count({ x,y }) > 0 && h < k) {
            h = k;
            S.erase({ x,y });
        }
    }
    cout << "Yes" << endl;

    return 0;
}
