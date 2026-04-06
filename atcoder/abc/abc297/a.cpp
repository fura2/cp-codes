#include "template.hpp"

int main() {
    int n, d; cin >> n >> d;
    vector<int> t(n);
    rep(i, n) cin >> t[i];

    rep(i, n - 1) if (t[i + 1] - t[i] <= d) {
        cout << t[i + 1] << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
