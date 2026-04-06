#include "template.hpp"

class mint {
    static const int MOD = 998244353;
    int x;
public:
    mint():x(0) {}
    mint(long long y) { x = y % MOD; if (x < 0) x += MOD; }

    mint& operator+=(const mint& m) { x += m.x; if (x >= MOD) x -= MOD; return *this; }
    mint& operator-=(const mint& m) { x -= m.x; if (x < 0) x += MOD; return *this; }
    mint& operator*=(const mint& m) { x = (long long)x * m.x % MOD; return *this; }
    mint& operator/=(const mint& m) { return *this *= inverse(m); }
    mint operator+(const mint& m)const { return mint(*this) += m; }
    mint operator-(const mint& m)const { return mint(*this) -= m; }
    mint operator*(const mint& m)const { return mint(*this) *= m; }
    mint operator/(const mint& m)const { return mint(*this) /= m; }
    mint operator-()const { return -x; }

    friend mint inverse(const mint& m) {
        int a = m.x, b = MOD, u = 1, v = 0;
        while (b > 0) { int t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        return u;
    }

    friend istream& operator>>(istream& is, mint& m) { long long t; is >> t; m = t; return is; }
    friend ostream& operator<<(ostream& os, const mint& m) { return os << m.x; }
    int to_int()const { return x; }
};

mint operator+(long long x, const mint& m) { return mint(x) + m; }
mint operator-(long long x, const mint& m) { return mint(x) - m; }
mint operator*(long long x, const mint& m) { return mint(x) * m; }
mint operator/(long long x, const mint& m) { return mint(x) / m; }

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    mint dp[101][1 << 11];
    dp[0][1] = 1;
    rep(i, n) {
        rep(d, 1, min(10, a[i]) + 1) {
            mint p = mint(1) / a[i]; // d が出る確率
            rep(S, 1 << 11) {
                int S2 = S | ((S << d) & ((1 << 11) - 1));
                dp[i + 1][S2] += dp[i][S] * p;
            }
        }

        if (a[i] > 10) {
            mint p = mint(a[i] - 10) / a[i]; // d より大きい数が出る確率
            rep(S, 1 << 11) {
                dp[i + 1][S] += dp[i][S] * p;
            }
        }
    }

    mint ans = 0;
    rep(S, 1 << 11) if (bit(S, 10)) ans += dp[n][S];
    cout << ans << endl;

    return 0;
}
