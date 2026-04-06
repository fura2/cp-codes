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

mint pow(mint m, long long k) {
    mint res = 1;
    for (; k > 0; k >>= 1, m *= m) if (k & 1) res *= m;
    return res;
}

mint factorial(int n) {
    static vector<mint> memo = { 1 };
    if (ssize(memo) <= n) {
        int k = memo.size();
        memo.resize(n + 1);
        for (; k <= n; k++) memo[k] = memo[k - 1] * k;
    }
    return memo[n];
}

mint factorial_inverse(int n) {
    static vector<mint> memo = { 1 };
    if (ssize(memo) <= n) {
        int k = memo.size();
        memo.resize(n + 1);
        memo[n] = inverse(factorial(n));
        for (int i = n; i > k; i--) memo[i - 1] = memo[i] * i;
    }
    return memo[n];
}

int main() {
    int n; cin >> n;
    vector<int> deg(n);
    rep(u, n) {
        cin >> deg[u];
        if (u != 0) deg[u]++;
    }

    mint denom_inv = 1; // 1 / ((deg(0) - 1)! * ... * (deg(n-1) - 1)!)
    rep(u, n) denom_inv *= factorial_inverse(deg[u] - 1);

    mint ans = factorial(n - 2) * denom_inv; // u = 0 からの寄与
    // dp[k][d] = (番号が r 以上の頂点集合から k 個選ぶ方法であって, 次数の和が d であるようなものの個数)
    vector dp(n + 1, vector(2 * n, mint(0)));
    dp[0][0] = 1;
    rrep(r, 1, n) {
        int deg_r = deg[r] - 1; // 部分木の根としての r の次数

        if (deg_r == 0) { // leaf
            ans += factorial(n - 2) * denom_inv;
        }
        else {
            rep(k, 2, n - r + 1) {
                if (2 * (k - 1) - deg_r >= 0) {
                    ans += dp[k - 1][2 * (k - 1) - deg_r] // 部分木の, 根 r 以外のサイズ k-1 の頂点集合の選び方の数
                        * factorial(k - 2) // 根および選んだ k-1 個の頂点でサイズ k の部分木を作る方法の数
                        * factorial(n - k - 1) // r を根とする部分木を 1 頂点に縮約したときの, n-k+1 頂点で木を作る方法の数
                        * (deg[r] - 1) * denom_inv; // (k-2)! と (n-k-1)! に付随する分母をまとめたもの
                }
            }
        }
        rrep(i, n - r) {
            rep(d, 2 * n - deg[r]) {
                dp[i + 1][d + deg[r]] += dp[i][d];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
