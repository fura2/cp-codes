#include "template.hpp"

class mint {
    static const int MOD = 998244353;
    int x;

  public:
    mint() : x(0) {}
    mint(long long y) {
        x = y % MOD;
        if (x < 0) x += MOD;
    }

    mint &operator+=(const mint &m) {
        x += m.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    mint &operator-=(const mint &m) {
        x -= m.x;
        if (x < 0) x += MOD;
        return *this;
    }
    mint &operator*=(const mint &m) {
        x = (long long)x * m.x % MOD;
        return *this;
    }
    mint &operator/=(const mint &m) {
        return *this *= inverse(m);
    }
    mint operator+(const mint &m) const {
        return mint(*this) += m;
    }
    mint operator-(const mint &m) const {
        return mint(*this) -= m;
    }
    mint operator*(const mint &m) const {
        return mint(*this) *= m;
    }
    mint operator/(const mint &m) const {
        return mint(*this) /= m;
    }
    mint operator-() const {
        return -x;
    }

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
    friend ostream &operator<<(ostream &os, const mint &m) {
        return os << m.x;
    }
    int to_int() const {
        return x;
    }
};

mint operator+(long long x, const mint &m) {
    return mint(x) + m;
}
mint operator-(long long x, const mint &m) {
    return mint(x) - m;
}
mint operator*(long long x, const mint &m) {
    return mint(x) * m;
}
mint operator/(long long x, const mint &m) {
    return mint(x) / m;
}

int a1, a2, a3;
int N[61]; // binary representation of n

bool vis[61][11][11][11][2][2][2][2][2][2];
mint memo[61][11][11][11][2][2][2][2][2][2];

mint dfs(
    int i,
    int mod1,
    int mod2,
    int mod3,
    bool smaller1,
    bool smaller2,
    bool smaller3,
    bool nonzero1,
    bool nonzero2,
    bool nonzero3
) {
    if (i == 61) {
        if (mod1 == 0 and mod2 == 0 and mod3 == 0 and nonzero1 and nonzero2 and nonzero3) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if (vis[i][mod1][mod2][mod3][smaller1][smaller2][smaller3][nonzero1][nonzero2][nonzero3]) {
        return memo[i][mod1][mod2][mod3][smaller1][smaller2][smaller3][nonzero1][nonzero2][nonzero3];
    }
    vis[i][mod1][mod2][mod3][smaller1][smaller2][smaller3][nonzero1][nonzero2][nonzero3] = true;

    mint &res = memo[i][mod1][mod2][mod3][smaller1][smaller2][smaller3][nonzero1][nonzero2][nonzero3];
    res = 0;
    rep (b1, 2) {
        if (not smaller1 and N[i] == 0 and b1 == 1) continue;
        rep (b2, 2) {
            if (not smaller2 and N[i] == 0 and b2 == 1) continue;
            int b3 = b1 ^ b2;
            if (not smaller3 and N[i] == 0 and b3 == 1) continue;

            res += dfs(
                i + 1,
                (2 * mod1 + b1) % a1,
                (2 * mod2 + b2) % a2,
                (2 * mod3 + b3) % a3,
                smaller1 or (N[i] == 1 and b1 == 0),
                smaller2 or (N[i] == 1 and b2 == 0),
                smaller3 or (N[i] == 1 and b3 == 0),
                nonzero1 or b1 == 1,
                nonzero2 or b2 == 1,
                nonzero3 or b3 == 1
            );
        }
    }
    return res;
}

int main() {
    lint n;
    cin >> n >> a1 >> a2 >> a3;

    rep (i, 61) N[i] = bit(n, 60 - i);

    cout << dfs(0, 0, 0, 0, false, false, false, false, false, false) << endl;

    return 0;
}
