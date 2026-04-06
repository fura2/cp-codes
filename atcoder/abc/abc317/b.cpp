#include "template.hpp"

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep (i, n) cin >> A[i];

    sort(all(A));

    rep (i, n - 1) {
        if (A[i] + 1 != A[i + 1]) {
            cout << A[i] + 1 << endl;
            break;
        }
    }

    return 0;
}
