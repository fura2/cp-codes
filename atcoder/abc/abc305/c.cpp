#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int h, w; cin >> h >> w;
    vector<string> B(h);
    rep(i, h) cin >> B[i];

    int t = h, b = 0, l = w, r = 0;
    rep(i, h) rep(j, w) if (B[i][j] == '#') {
        t = min(t, i);
        b = max(b, i + 1);
        l = min(l, j);
        r = max(r, j + 1);
    }

    for (int i = t; i < b; i++) for (int j = l; j < r; j++) if (B[i][j] == '.') {
        cout << i + 1 << " " << j + 1 << endl;
        return 0;
    }

    return 0;
}
