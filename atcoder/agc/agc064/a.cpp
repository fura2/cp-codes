#include "template.hpp"

int main() {
    int n;
    cin >> n;

    vector<int> A;
    int k = n - 2;
    while (k >= 0) {
        rep(j, k) {
            A.emplace_back(k + 2);
            A.emplace_back(k + 1);
        }
        A.emplace_back(k + 2);
        k -= 2;
    }
    rep(j, n) A.emplace_back(j + 1);
    swap(A.back(), A[ssize(A) - 2]);

    for (int a : A)
        cout << a << " ";

    return 0;
}
