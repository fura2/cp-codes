#include "template.hpp"

class mint {
    static const int MOD = 998244353;
    int x;

  public:
    mint() : x(0) {}
    mint(long long y) {
        x = y % MOD;
        if (x < 0)
            x += MOD;
    }

    mint &operator+=(const mint &m) {
        x += m.x;
        if (x >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator-=(const mint &m) {
        x -= m.x;
        if (x < 0)
            x += MOD;
        return *this;
    }
    mint &operator*=(const mint &m) {
        x = (long long)x * m.x % MOD;
        return *this;
    }
    mint &operator/=(const mint &m) { return *this *= inverse(m); }
    mint operator+(const mint &m) const { return mint(*this) += m; }
    mint operator-(const mint &m) const { return mint(*this) -= m; }
    mint operator*(const mint &m) const { return mint(*this) *= m; }
    mint operator/(const mint &m) const { return mint(*this) /= m; }
    mint operator-() const { return -x; }

    friend mint inverse(const mint &m) {
        int a = m.x, b = MOD, u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return u;
    }

    friend istream &operator>>(istream &is, mint &m) {
        long long t;
        is >> t;
        m = t;
        return is;
    }
    friend ostream &operator<<(ostream &os, const mint &m) { return os << m.x; }
    int to_int() const { return x; }
};

mint operator+(long long x, const mint &m) { return mint(x) + m; }
mint operator-(long long x, const mint &m) { return mint(x) - m; }
mint operator*(long long x, const mint &m) { return mint(x) * m; }
mint operator/(long long x, const mint &m) { return mint(x) / m; }

mint pow(mint m, long long k) {
    mint res = 1;
    for (; k > 0; k >>= 1, m *= m)
        if (k & 1)
            res *= m;
    return res;
}

mint factorial(int n) {
    static vector<mint> memo = {1};
    if (memo.size() <= n) {
        int k = memo.size();
        memo.resize(n + 1);
        for (; k <= n; k++)
            memo[k] = memo[k - 1] * k;
    }
    return memo[n];
}

mint factorial_inverse(int n) {
    static vector<mint> memo = {1};
    if (memo.size() <= n) {
        int k = memo.size();
        memo.resize(n + 1);
        memo[n] = inverse(factorial(n));
        for (int i = n; i > k; i--)
            memo[i - 1] = memo[i] * i;
    }
    return memo[n];
}

mint choose(int n, int k, int type = 0) {
    if (k == 0)
        return 1;
    if (n < k)
        return 0;
    if (type == 0) {
        return factorial(n) * factorial_inverse(k) * factorial_inverse(n - k);
    } else {
        if (k > n - k)
            k = n - k;
        mint res = factorial_inverse(k);
        rep(i, k) res *= n - i;
        return res;
    }
}

mint multichoose(int n, int k, int type = 0) {
    return choose(n + k - 1, k, type);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    k--;

    vector<int> hist(m + 1);
    rep(i, n) hist[A[i]]++;

    vector<mint> res(m + 1); // res[v] = (操作後に A_k <= v となる場合の数)
    rep(v, 1, m + 1) {
        int cnt = accumulate(hist.begin() + 1, hist.begin() + v + 1, 0);
        rep(i, hist[0] + 1) { // v 以下が i 個, v より大が hist[0]-i 個
            if (cnt + i >= k + 1) {
                res[v] += choose(hist[0], i) * pow(mint(v), i) * pow(mint(m - v), hist[0] - i);
            }
        }
    }

    mint ans = 0;
    rep(v, 1, m + 1) ans += (res[v] - res[v - 1]) * v;
    ans /= pow(mint(m), hist[0]);
    cout << ans << endl;

    return 0;
}
