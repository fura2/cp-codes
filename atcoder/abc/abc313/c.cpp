#include "template.hpp"

int main() {
    int n; cin >> n;
    vector<lint> A(n);
    rep(i, n) cin >> A[i];

    sort(all(A));

    lint sum = accumulate(all(A), 0LL);
    vector<lint> B(n, sum / n);
    rep(i, sum % n) B[n - i - 1]++;

    lint ans = 0;
    rep(i, n) ans += abs(A[i] - B[i]);
    cout << ans / 2 << endl;

    return 0;
}
