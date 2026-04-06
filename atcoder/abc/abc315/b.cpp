#include "template.hpp"

int main() {
    int m;
    cin >> m;
    vector<int> D(m);
    rep(i, m) cin >> D[i];

    int total = accumulate(all(D), 0);
    int sum = 0;
    rep(i, m) {
        if (sum + D[i] > total / 2) {
            cout << i + 1 << " " << total / 2 - sum + 1 << endl;
            break;
        }
        sum += D[i];
    }

    return 0;
}
