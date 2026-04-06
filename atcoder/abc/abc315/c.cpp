#include "template.hpp"

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n);
    rep(i, n) {
        int f, s;
        cin >> f >> s;
        f--;
        A[f].emplace_back(s);
    }

    rep(i, n) sort(A[i].rbegin(), A[i].rend());

    vector<int> T;
    rep(i, n) if (!A[i].empty()) T.emplace_back(A[i][0]);
    sort(T.rbegin(), T.rend());

    int ans = 0;
    if (T.size() >= 2) {
        chmax(ans, T[0] + T[1]);
    }
    rep(i, n) {
        if (A[i].size() >= 2) {
            chmax(ans, A[i][0] + A[i][1] / 2);
        }
    }
    cout << ans << endl;

    return 0;
}
