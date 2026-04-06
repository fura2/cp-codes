#include "template.hpp"

int main() {
    int n, m; cin >> n >> m;
    vector<lint> A(n), B(n), C(n);
    rep(i, n) {
        int t;
        lint x; cin >> t >> x;
        if (t == 0) A.emplace_back(x);
        if (t == 1) B.emplace_back(x);
        if (t == 2) C.emplace_back(x);
    }

    sort(all(B));
    sort(rbegin(C), rend(C));

    lint ans = 0, sum = 0;
    int cap = m;
    priority_queue<lint, vector<lint>, greater<>> Q;
    for (auto a : A) {
        sum += a;
        Q.emplace(a);
    }
    while (ssize(Q) > cap) {
        sum -= Q.top();
        Q.pop();
    }
    chmax(ans, sum);

    int rem = 0;
    for (auto c : C) {
        cap--; // use an opener
        if (cap < 0) break;
        rem += c;
        while (rem > 0 && !B.empty()) {
            sum += B.back();
            Q.emplace(B.back());
            B.pop_back();
            while (ssize(Q) > cap) {
                sum -= Q.top();
                Q.pop();
            }
            chmax(ans, sum);
            rem--;
        }
    }
    cout << ans << endl;

    return 0;
}
