#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n;
    string s, t; cin >> n >> s >> t;

    auto f = [](char c, char d) {
        if (c == d) return true;
        if (c == '1' && d == 'l') return true;
        if (c == 'l' && d == '1') return true;
        if (c == '0' && d == 'o') return true;
        if (c == 'o' && d == '0') return true;
        return false;
    };

    bool ok = true;
    rep(i, n) if (!f(s[i], t[i])) ok = false;
    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
