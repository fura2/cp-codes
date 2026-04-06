#include "template.hpp"

int main() {
    int n, m; cin >> n >> m;
    vector<int> A(n), B(m);
    rep(i, n) cin >> A[i];
    rep(j, m) cin >> B[j];

    int lo = 0, hi = 1e9 + 1;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        int cnt = 0;
        rep(i, n) if (mid >= A[i]) cnt++;
        rep(j, m) if (mid <= B[j]) cnt--;
        (cnt < 0 ? lo : hi) = mid;
    }
    cout << lo + 1 << endl;

    return 0;
}
