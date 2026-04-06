#include "template.hpp"

int main() {
    int n; cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    cout << max(*max_element(A.begin() + 1, A.end()) - A[0] + 1, 0) << endl;

    return 0;
}
