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

// s と t の共通部分列
//   s[i_1]s[i_2]...s[i_k] = t[i_1]t[j_2]...t[j_k]
// であって, 次の二つの条件を満たすものの個数
// - i_1 = j_1 = 0
// - (i_1, ..., i_k を貪欲に (左詰めに) 選んだとき) s の i_k + 1 文字目以降には s[0] が現れない
mint f(string s, string t) {
    assert(s[0] == t[0]);

    int m = s.size(), n = t.size();
    vector next_s(m, vector(26, -1));
    vector next_t(n, vector(26, -1));
    rrep(i, m - 1) {
        rep(c, 26) next_s[i][c] = next_s[i + 1][c];
        next_s[i][s[i + 1] - 'a'] = i + 1;
    }
    rrep(j, n - 1) {
        rep(c, 26) next_t[j][c] = next_t[j + 1][c];
        next_t[j][t[j + 1] - 'a'] = j + 1;
    }

    vector dp(m, vector(n, mint(0)));
    dp[0][0] = 1;
    rep(i, m) rep(j, n) {
        rep(c, 26) if (next_s[i][c] != -1 && next_t[j][c] != -1) {
            dp[next_s[i][c]][next_t[j][c]] += dp[i][j];
        }
    }

    mint res = 0;
    rrep(i, m) {
        rep(j, n) res += dp[i][j];
        if (s[i] == s[0]) break;
    }
    return res;
}

int main() {
    string s; cin >> s;
    int n = s.size();

    mint ans = 0;
    rep(i2, 1, n) {
        bool used[128] = {};
        rep(i1, i2) if (s[i1] == s[i2] && !used[int(s[i1])]) {
            used[int(s[i1])] = true;
            ans += f(s.substr(i1, i2 - i1), s.substr(i2));
        }
    }
    cout << ans << endl;

    return 0;
}
