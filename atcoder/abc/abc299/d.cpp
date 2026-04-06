#include "template.hpp"

int ask(int x) {
    cout << "? " << x + 1 << endl;
    int res; cin >> res;
    return res;
}

int main() {
    int n; cin >> n;

    int lo = 0, hi = n - 1;
    while (hi - lo > 1) {
        int mi = (lo + hi) / 2;
        if (ask(mi) == 0) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }
    cout << "! " << lo + 1 << endl;

    return 0;
}
