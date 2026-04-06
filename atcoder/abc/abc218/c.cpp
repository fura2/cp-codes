#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

vector<string> trim(vector<string> S) {
    int n = S.size();
    int t = n, b = 0, l = n, r = 0;
    rep(i, n) rep(j, n) if (S[i][j] == '#') {
        t = min(t, i);
        b = max(b, i + 1);
        l = min(l, j);
        r = max(r, j + 1);
    }

    vector<string> res(b - t, string(r - l, '.'));
    rep(i, b - t) rep(j, r - l) {
        res[i][j] = S[t + i][l + j];
    }
    return res;
}

vector<string> rot(vector<string> S) {
    int n = S.size();
    auto res = S;
    rep(i, n) rep(j, n) res[j][n - i - 1] = S[i][j];
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    vector<string> S(n), T(n);
    rep(i, n) cin >> S[i];
    rep(i, n) cin >> T[i];

    rep(t, 4) {
        if (trim(S) == trim(T)) {
            cout << "Yes" << endl;
            return 0;
        }
        T = rot(T);
    }
    cout << "No" << endl;

    return 0;
}
