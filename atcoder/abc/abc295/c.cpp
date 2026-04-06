#include "template.hpp"

int main() {
    int n;
    cin >> n;
    map<int, int> f;
    rep(i, n) {
        int a;
        cin >> a;
        ++f[a];
    }

    int ans = 0;
    for (auto [k, v] : f)
        ans += v / 2;
    cout << ans << endl;

    return 0;
}
