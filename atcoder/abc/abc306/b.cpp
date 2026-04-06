#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    unsigned long ans = 0;
    rep(i, 64) {
        unsigned long x; cin >> x;
        ans |= x << i;
    }
    cout << ans << endl;

    return 0;
}
