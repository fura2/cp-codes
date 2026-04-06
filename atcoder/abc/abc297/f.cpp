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
    if (memo.size() <= n) {
        int k = memo.size();
        memo.resize(n + 1);
        for (; k <= n; k++) memo[k] = memo[k - 1] * k;
    }
    return memo[n];
}

mint factorial_inverse(int n) {
    static vector<mint> memo = { 1 };
    if (memo.size() <= n) {
        int k = memo.size();
        memo.resize(n + 1);
        memo[n] = inverse(factorial(n));
        for (int i = n; i > k; i--) memo[i - 1] = memo[i] * i;
    }
    return memo[n];
}

mint choose(int n, int k, int type = 0) {
    if (k == 0) return 1;
    if (n < k) return 0;
    if (type == 0) {
        return factorial(n) * factorial_inverse(k) * factorial_inverse(n - k);
    }
    else {
        if (k > n - k) k = n - k;
        mint res = factorial_inverse(k);
        rep(i, k) res *= n - i;
        return res;
    }
}

mint multichoose(int n, int k, int type = 0) {
    return choose(n + k - 1, k, type);
}

int main() {
    int h, w, k; cin >> h >> w >> k;

    // 選んだ k 個のマスの bounding box が [0, a) x [0, b) に含まれる選び方の数は C(a*b, k).
    //   c[a][b] = (選んだ k 個のマスの bounding box が [0, a) x [0, b) に一致する選び方の数)
    // とおくと,
    //   C(a*b, k) = Σ_{1<=i<=a, 1<=j<=b} (a-i+1)*(b-j+1)*c[i][j].
    // これを使うと i, j の小さい順に c[i][j] が求まる.

    // // naive, too slow
    // vector c(h + 1, vector(w + 1, mint(0)));
    // rep(a, 1, h + 1) rep(b, 1, w + 1) {
    //     c[a][b] = choose(a * b, k);
    //     rep(i, 1, a + 1) rep(j, 1, b + 1) if (!(i == a && j == b)) {
    //         c[a][b] -= (a - i + 1) * (b - j + 1) * c[i][j];
    //     }
    // }

    // speed up
    //   d[i][j] = Σ_{0<=i'<i, 0<=j'<j} c[i][j]
    //   di[i][j] = Σ_{0<=i'<i, 0<=j'<j} i * c[i][j]
    //   dj[i][j] = Σ_{0<=i'<i, 0<=j'<j} j * c[i][j]
    //   dij[i][j] = Σ_{0<=i'<i, 0<=j'<j} i * j * c[i][j]
    vector d(h + 2, vector(w + 2, mint(0)));
    vector di(h + 2, vector(w + 2, mint(0)));
    vector dj(h + 2, vector(w + 2, mint(0)));
    vector dij(h + 2, vector(w + 2, mint(0)));
    rep(a, 1, h + 1) rep(b, 1, w + 1) {
        d[a + 1][b + 1] = d[a + 1][b] + d[a][b + 1] - d[a][b];
        di[a + 1][b + 1] = di[a + 1][b] + di[a][b + 1] - di[a][b];
        dj[a + 1][b + 1] = dj[a + 1][b] + dj[a][b + 1] - dj[a][b];
        dij[a + 1][b + 1] = dij[a + 1][b] + dij[a][b + 1] - dij[a][b];

        mint c = choose(a * b, k)
            - (a + 1) * (b + 1) * d[a + 1][b + 1]
            + (b + 1) * di[a + 1][b + 1]
            + (a + 1) * dj[a + 1][b + 1]
            - dij[a + 1][b + 1];

        d[a + 1][b + 1] += c;
        di[a + 1][b + 1] += a * c;
        dj[a + 1][b + 1] += b * c;
        dij[a + 1][b + 1] += a * b * c;
    }

    mint ans = 0;
    rep(a, 1, h + 1) rep(b, 1, w + 1) {
        mint c = d[a + 1][b + 1] - d[a + 1][b] - d[a][b + 1] + d[a][b];
        ans += (h - a + 1) * (w - b + 1) * c * (a * b);
    }
    ans /= choose(h * w, k);
    cout << ans << endl;

    return 0;
}
