#include "template.hpp"

int main() {
    int n, p, q; cin >> n >> p >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    cout << min(p, q + *min_element(all(a))) << endl;

    return 0;
}
