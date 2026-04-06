#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

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
    for (;k > 0;k >>= 1, m *= m) if (k & 1) res *= m;
    return res;
}

vector<long long> divisors(long long a) {
    vector<long long> res;
    for (long long i = 1;i * i <= a;i++) if (a % i == 0) {
        res.emplace_back(i);
        if (i * i < a) res.emplace_back(a / i);
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n;
    string s; cin >> n >> s;

    auto D = divisors(n);

    vector<mint> res(n);
    for (auto d : D) if (d < n) {
        int len = d;
        vector<int> t(len, 0); // 0: don't care, 1: '#'
        rep(i, n) if (s[i] == '.') t[i % len] = 1;
        mint x = pow(mint(2), count(t.begin(), t.end(), 0));
        res[len] += x;
        for (auto e : D) if (d < e && e < n && e % d == 0) res[e] -= res[len];
    }
    cout << accumulate(res.begin(), res.end(), mint(0)) << '\n';

    return 0;
}
