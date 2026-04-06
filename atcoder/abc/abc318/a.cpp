#include "template.hpp"

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    int ans = 0;
    rep (i, m, n + 1) {
        if ((i - m) % p == 0) ans++;
    }
    cout << ans << endl;

    return 0;
}
