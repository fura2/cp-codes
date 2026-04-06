#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    rep(i, 26) {
        int p; cin >> p;
        cout << char('a' + p - 1);
    }



    return 0;
}
