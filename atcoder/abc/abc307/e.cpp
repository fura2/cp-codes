// 1 と N の色が同じかどうかで場合分け

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
    for (; k > 0; k >>= 1, m *= m) if (k & 1) res *= m;
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, m; cin >> n >> m;
    vector<mint> a(n + 1);
    a[1] = m;
    a[2] = mint(m) * (m - 1);
    for (int i = 2; i < n; i++) a[i + 1] = mint(m) * pow(mint(m - 1), i) - a[i];
    cout << a[n] << endl;

    return 0;
}
