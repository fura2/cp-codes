#include "template.hpp"

lint length(vector<pair<lint, lint>> I) {
    int n = size(I);
    sort(all(I));

    lint res = 0;
    lint l = LLONG_MIN, r = LLONG_MIN;
    rep (i, n + 1) {
        if (i == n or r < I[i].first) {
            res += r - l;
            if (i < n) tie(l, r) = I[i];
        }
        else {
            chmax(r, I[i].second);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<lint> X(n), L(n);
    rep (i, n) cin >> X[i];
    rep (i, n) cin >> L[i];

    // タコの頭の位置 c を決めたとき, c に近い X_i から順に短い足を割り当てるとしてよい.
    // この割り当て方で問題の条件をみたすことができる c の集合は区間になる.
    // c を動かしたときに {|X_i - c|}_i の位置関係が変わるタイミングは, c が X_i と X_j の
    // 中点をまたぐときなので, それらを全部試す.
    vector<lint> C = X; // candidates
    rep (i, n) {
        rep (j, i + 1, n) {
            C.emplace_back((X[i] + X[j] - 1) / 2);
            C.emplace_back((X[i] + X[j]) / 2);
            C.emplace_back((X[i] + X[j] + 1) / 2);
        }
    }
    sort(all(C));
    C.erase(unique(all(C)), end(C));

    vector<pair<lint, lint>> I; // intervals
    for (auto c: C) {
        vector<lint> D(n);
        rep (i, n) D[i] = abs(X[i] - c);
        vector<int> P(n);
        iota(all(P), 0);
        sort(all(P), [&](int i, int j) { return D[i] < D[j]; });

        lint mn = LLONG_MIN, mx = LLONG_MAX;
        rep (i, n) {
            chmax(mn, X[P[i]] - L[i]);
            chmin(mx, X[P[i]] + L[i]);
        }
        if (mn <= mx) {
            I.emplace_back(mn, mx + 1);
        }
    }

    cout << length(I) << endl;

    return 0;
}
