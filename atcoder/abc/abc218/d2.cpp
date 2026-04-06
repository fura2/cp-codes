// O(N^{3/2}) solution
// https://atcoder.jp/contests/abc218/editorial/2636

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vector<vector<int>> Y;
    {
        unordered_map<int, vector<int>> f;
        rep(i, n) f[x[i]].emplace_back(y[i]);
        for (auto& [k, v] : f) {
            sort(v.begin(), v.end());
            Y.emplace_back(v);
        }
    }

    int sqrtn = sqrt(n);
    // Y[0,k) : size <= √n, Y[k,n) : size > √n
    int k = partition(Y.begin(), Y.end(), [&](const vector<int>& v) { return v.size() <= sqrtn; }) - Y.begin();

    int ans = 0;
    // small x small
    // Σ_{i=1}^k size[i]^2 = O(n√n) for size[i] <= √n and Σ_{i=1}^k size[i] <= n
    unordered_map<long, int> h; // (y1, y2) -> count
    rep(i, k) {
        rep(j1, Y[i].size()) for (int j2 = j1 + 1; j2 < Y[i].size(); j2++) {
            long y1 = Y[i][j1], y2 = Y[i][j2];
            ans += h[(y1 << 30) + y2];
        }
        rep(j1, Y[i].size()) for (int j2 = j1 + 1; j2 < Y[i].size(); j2++) {
            long y1 = Y[i][j1], y2 = Y[i][j2];
            ++h[(y1 << 30) + y2];
        }
    }
    // large x any
    for (int i1 = k; i1 < Y.size(); i1++) { // O(√n)
        unordered_set<int> g(Y[i1].begin(), Y[i1].end());
        rep(i2, i1) {
            int cnt = 0;
            rep(j, Y[i2].size()) { // O(n)
                if (g.count(Y[i2][j]) > 0) {
                    ans += cnt;
                    cnt++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
