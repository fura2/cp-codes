#include "template.hpp"

int ask(const vector<int> &V) {
    cout << "?";
    for (int a : V)
        cout << " " << a + 1;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> res(k + 1);
    rep(i, k + 1) {
        vector<int> V;
        rep(j, k + 1) if (j != i) V.emplace_back(j);
        res[i] = ask(V);
    }

    int sum = 0; // 先頭 k+1 項の和
    rep(i, k + 1) sum ^= res[i];

    vector<int> ans(n);
    rep(i, k + 1) ans[i] = sum ^ res[i];
    rep(i, k + 1, n) {
        vector<int> V(k);
        rep(j, k - 1) V[j] = j;
        V[k - 1] = i;
        ans[i] = ask(V) ^ sum ^ ans[k - 1] ^ ans[k];
    }
    cout << "!";
    rep(i, n) cout << " " << ans[i];
    cout << endl;

    return 0;
}
