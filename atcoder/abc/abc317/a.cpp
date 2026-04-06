#include "template.hpp"

int main() {
    int n, h, x;
    cin >> n >> h >> x;
    vector<int> P(n);
    rep (i, n) cin >> P[i];

    rep (i, n) {
        if (h + P[i] >= x) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}
