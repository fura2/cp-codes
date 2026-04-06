#include "template.hpp"

int main() {
    int n;
    cin >> n;
    vector<lint> A(n);
    rep (i, n) cin >> A[i], A[i]--;

    int m = 3e5;
    vector<lint> Hl(m), Hr(m); // histograms
    rep (i, n) Hr[A[i]]++;

    lint ans = 0;
    lint sum = 0; // Σ_a Hl[a] * Hr[a]
    for (lint a: A) {
        sum -= Hl[a] * Hr[a];
        ans += sum;
        Hl[a]++;
        Hr[a]--;
        sum += Hl[a] * Hr[a];
    }
    cout << ans << endl;

    return 0;
}
