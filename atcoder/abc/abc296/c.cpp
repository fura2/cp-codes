#include "template.hpp"

int main() {
    int n, x; cin >> n >> x;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    sort(all(A));

    rep(i, n) {
        if (binary_search(all(A), x + A[i])) {
            yes();
            return 0;
        }
    }
    no();

    return 0;
}
