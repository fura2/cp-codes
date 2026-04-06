#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int d[] = { 0, 3, 1, 4, 1, 5, 9 };
    rep(i, 6) d[i + 1] += d[i];

    char p, q; cin >> p >> q;
    cout << abs(d[p - 'A'] - d[q - 'A']) << endl;

    return 0;
}
