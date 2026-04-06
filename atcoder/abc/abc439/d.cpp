#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> L, R;
    for (int i = 0; i < n; i++) {
        R[a[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        R[a[i]]--;

        if (a[i] % 5 == 0) {
            int x = a[i] / 5 * 3;
            int y = a[i] / 5 * 7;
            ans += 1LL * R[x] * R[y];
            ans += 1LL * L[x] * L[y];
        }

        L[a[i]]++;
    }
    cout << ans << endl;

    return 0;
}
