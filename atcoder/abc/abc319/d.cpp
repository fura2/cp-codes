#include "template.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    vector<lint> L(n);
    rep (i, n) cin >> L[i];

    lint lo = *max_element(all(L)) - 1;
    lint hi = accumulate(all(L), 0LL) + n;
    while (hi - lo > 1) {
        lint mid = (lo + hi) / 2;
        int row = 0;
        lint col = 0;
        rep (i, n) {
            if (col == 0) {
                row++;
                col += L[i];
            }
            else {
                if (col + 1 + L[i] <= mid) {
                    col += 1 + L[i];
                }
                else {
                    row++;
                    col = L[i];
                }
            }
        }
        (row <= m ? hi : lo) = mid;
    }
    cout << hi << endl;

    return 0;
}
