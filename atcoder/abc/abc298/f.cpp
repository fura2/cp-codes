#include "template.hpp"

int main() {
    int n; cin >> n;
    vector<int> row(n), col(n);
    vector<lint> val(n);
    rep(i, n) cin >> row[i] >> col[i] >> val[i];

    map<int, lint> rowsum, colsum;
    map<int, vector<pair<int, int>>> row2cols;
    rep(i, n) {
        rowsum[row[i]] += val[i];
        colsum[col[i]] += val[i];
        row2cols[row[i]].emplace_back(col[i], i);
    }

    multiset<lint> CS; // colsum values
    for (auto [c, sum] : colsum) CS.emplace(sum);

    lint ans = 0;
    for (auto [r, sum] : rowsum) {
        for (auto [c, i] : row2cols[r]) {
            CS.erase(CS.find(colsum[c]));
        }
        if (!CS.empty()) {
            chmax(ans, sum + *CS.rbegin());
        }
        for (auto [c, i] : row2cols[r]) {
            CS.emplace(colsum[c]);
            chmax(ans, sum + colsum[c] - val[i]);
        }
    }
    cout << ans << endl;

    return 0;
}
