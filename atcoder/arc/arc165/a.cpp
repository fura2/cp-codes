#include "template.hpp"

map<long long, int> prime_factorize(long long a) {
    map<long long, int> res;
    if (a % 2 == 0) {
        int cnt = 0;
        do {
            cnt++;
            a /= 2;
        } while (a % 2 == 0);
        res.emplace(2, cnt);
    }
    for (long long p = 3; p * p <= a; p += 2)
        if (a % p == 0) {
            int cnt = 0;
            do {
                cnt++;
                a /= p;
            } while (a % p == 0);
            res.emplace(p, cnt);
        }
    if (a > 1) res.emplace(a, 1);
    return res;
}

void solve() {
    lint n;
    cin >> n;
    yesno(size(prime_factorize(n)) >= 2);
}

int main() {
    int t;
    cin >> t;
    rep (t) solve();
    return 0;
}
