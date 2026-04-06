#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    int ans = 0;
    for (int x = 5; x <= 100; x += 5) if (abs(ans - n) > abs(x - n)) ans = x;
    cout << ans << endl;

    return 0;
}
