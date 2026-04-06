#include "template.hpp"

int main() {
    int n, k; cin >> n >> k;
    vector<lint> A(n);
    rep(i, n) cin >> A[i];
    sort(all(A));

    set<lint> S;
    priority_queue<lint> Q;
    Q.emplace(0);
    while (ssize(S) <= k) {
        lint x = -Q.top(); Q.pop();
        if (S.count(x) > 0) continue;
        S.emplace(x);
        rep(i, n) Q.emplace(-(x + A[i]));
    }
    cout << *S.rbegin() << endl;

    return 0;
}
