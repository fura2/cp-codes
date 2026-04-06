#include <bits/stdc++.h>

using namespace std;

int c[10000001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; i++) {
        for (int j = i + 1; j * j <= n - i * i; j++) {
            c[i * i + j * j]++;
        }
    }
    vector<int> ans;
    for (int x = 1; x <= n; x++) {
        if (c[x] == 1) {
            ans.emplace_back(x);
        }
    }

    cout << ans.size() << endl;
    for (int x: ans) cout << x << " ";
    cout << endl;

    return 0;
}
