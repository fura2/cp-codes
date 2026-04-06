#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    if (n < 1e3);
    else if (n < 1e4) n = n / 10 * 10;
    else if (n < 1e5) n = n / 100 * 100;
    else if (n < 1e6) n = n / 1000 * 1000;
    else if (n < 1e7) n = n / 10000 * 10000;
    else if (n < 1e8) n = n / 100000 * 100000;
    else if (n < 1e9) n = n / 1000000 * 1000000;
    cout << n << endl;

    return 0;
}
