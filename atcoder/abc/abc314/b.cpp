#include "template.hpp"

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n);
    rep(i, n) {
        int k;
        cin >> k;
        A[i].resize(k);
        rep(j, k) cin >> A[i][j];
    }
    int x;
    cin >> x;

    vector<int> ans;
    int num = 1000000;
    rep(i, n) if (count(all(A[i]), x) > 0) {
        if (num > ssize(A[i])) {
            ans.clear();
            num = ssize(A[i]);
        }
        if (num == ssize(A[i])) {
            ans.emplace_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int a : ans)
        cout << a + 1 << " ";

    return 0;
}
