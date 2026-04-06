#include "template.hpp"

template <class T>
T xgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T g = xgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

// floor(a / b), assume b > 0, not assume a >= 0
template <typename T>
lint floor(const T &a, const T &b) {
    return a >= 0 ? a / b : (a - b + 1) / b;
}

// ceil(a / b), assume b > 0, not assume a >= 0
template <typename T>
lint ceil(const T &a, const T &b) {
    return a >= 0 ? (a + b - 1) / b : a / b;
}

int main() {
    lint n, a, b, c, x;
    cin >> n >> a >> b >> c >> x;

    lint g = gcd(b, c);
    b /= g;
    c /= g;

    // assume m > 0
    // find all l s.t. 1 <= j + lm <= n
    auto f = [](__int128 j, __int128 m, __int128 n) -> pair<__int128, __int128> {
        return {ceil(1 - j, m), floor(n - j, m)};
    };

    lint ans = 0;
    rep(i, 1, n + 1) {
        lint y = x - a * i;
        if (y % g != 0) {
            continue;
        }
        y /= g;

        // solve bj + ck = 1
        // any solution can be written as (j + lc, k - lb) for any integer l
        lint j, k;
        xgcd(b, c, j, k);
        // any solution of
        //   bj + ck = y
        // can be written as (jy + lc, ky - lb) for any integer l

        auto Ij = f(__int128(j) * y, c, n);
        auto Ik = f(__int128(k) * y, b, n);
        Ik = {-Ik.second, -Ik.first};
        ans += max(min(Ij.second, Ik.second) - max(Ij.first, Ik.first) + 1, __int128(0));
    }
    cout << ans << endl;

    return 0;
}
