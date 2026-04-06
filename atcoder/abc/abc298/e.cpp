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

vector<mint> f(int n, int k) {
    mint p = mint(1) / k;
    vector dp(n + 1, vector(n, mint(0)));
    dp[0][0] = 1;
    rep(t, n) {
        rep(x, n) {
            rep(j, 1, k + 1) {
                dp[t + 1][min(x + j, n - 1)] += p * dp[t][x];
            }
        }
    }

    // res[i] = (nマス, k面ダイスのすごろくで, ダイスをちょうどi回振ってゴールする確率)
    vector<mint> res(n + 1);
    res[0] = dp[0].back();
    rep(t, n) res[t] = dp[t + 1].back() - dp[t].back();
    return res;
}

int main() {
    int n, a, b, p, q; cin >> n >> a >> b >> p >> q; a--; b--;

    auto res1 = f(n - a, p);
    auto res2 = f(n - b, q);

    mint res = 0;
    rep(i, ssize(res1)) rep(j, i, ssize(res2)) res += res1[i] * res2[j];
    cout << res << endl;

    return 0;
}
