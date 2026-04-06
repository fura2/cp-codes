#include "template.hpp"

int grundy(int a, int l, int r) {
    return (a % (l + r)) / l;
}

int main() {
    int n, l, r; cin >> n >> l >> r;
    int g = 0;
    rep(i, n) {
        int a; cin >> a;
        g ^= grundy(a, l, r);
    }
    cout << (g > 0 ? "First" : "Second") << endl;

    return 0;
}
