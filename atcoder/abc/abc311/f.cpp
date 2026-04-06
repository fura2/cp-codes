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
    int h, w; cin >> h >> w;
    vector<string> B(h);
    rep(i, h) cin >> B[i];

    rep(i, h) rep(j, w) if (B[i][j] == '#') {
        if (i < h - 1) B[i + 1][j] = '#';
        if (i < h - 1 && j < w - 1) B[i + 1][j + 1] = '#';
    }

    // validな盤面では, 各列は「上から下に, あるマスまでが白でそれ以降が黒」という形になる.
    // 与えられた盤面 (の黒にする必要があるマスを黒にしたもの) の j 列目の黒マスの個数を a_j とする.
    // j 列目に黒マスが c_j 個ある盤面がvalidであるためには
    //   0 <= c_j <= h かつ c_j <= c_{j+k} + k for all j, k > 0
    // が必要十分. これが与えられた盤面から作れるための条件 a_j <= c_j も合わせて,
    //   a_j <= c_j <= h かつ c_j <= c_{j+k} + k for all j, k > 0
    // を満たす c = (c_1, ..., c_w) を数えればよい.
    //   b_j = c_j + j
    // と変換すると, c の条件は
    //   a_j + j <= b_j <= h + j かつ b_j <= b_k for all j < k
    // と書き直せる. この方が見やすい.
    vector<int> a(w);
    rep(i, h) rep(j, w) if (B[i][j] == '#') chmax(a[j], h - i);
    rep(j, w) a[j] += j;

    vector dp(w + 1, vector(h + w, mint(0)));
    dp[0][0] = 1;
    rep(j, w) {
        mint cum = 0;
        rep(k, a[j]) cum += dp[j][k];
        rep(k, a[j], h + j + 1) {
            cum += dp[j][k];
            dp[j + 1][k] = cum;
        }
    }
    cout << accumulate(all(dp.back()), mint(0)) << endl;

    return 0;
}
