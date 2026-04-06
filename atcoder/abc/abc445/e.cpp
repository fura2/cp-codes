#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define impl_overload4(a, b, c, d, e, ...) e
#define impl_overload5(a, b, c, d, e, f, ...) f
#define impl_overload6(a, b, c, d, e, f, g, ...) g
#define impl_overload7(a, b, c, d, e, f, g, h, ...) h

// clang-format off
#define impl_rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define impl_rep3(i, a, b) impl_rep4(i, a, b, 1)
#define impl_rep2(i, n) impl_rep3(i, 0, n)
#define impl_rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) impl_overload4(__VA_ARGS__, impl_rep4, impl_rep3, impl_rep2, impl_rep1)(__VA_ARGS__)

#define impl_rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define impl_rrep3(i, a, b) impl_rrep4(i, a, b, 1)
#define impl_rrep2(i, n) impl_rrep3(i, 0, n)
#define rrep(...) impl_overload4(__VA_ARGS__, impl_rrep4, impl_rrep3, impl_rrep2)(__VA_ARGS__)
// clang-format on

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)

template<typename T>
constexpr int bit(T x, unsigned int k) {
    return (x >> k) & 1;
}

template<typename T>
constexpr bool chmax(T& a, const T& b) {
    return a < b ? a = b, true : false;
}
template<typename T>
constexpr bool chmin(T& a, const T& b) {
    return a > b ? a = b, true : false;
}

void yesno(bool b) {
    std::cout << (b ? "Yes" : "No") << "\n";
}
void yes() {
    yesno(true);
}
void no() {
    yesno(false);
}

struct Setup {
    Setup() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(11);
    }
} setup;

#ifdef LOCAL
#include "template_local.hpp"
#else
#define show(...) ((void)0)
#endif

using uint = unsigned int;
using lint = long long;
using ulint = unsigned long long;

using namespace std;

#endif // TEMPLATE_HPP

class mint {
    static const int MOD = 998244353;
    int x;

  public:
    mint(): x(0) {}
    mint(long long y) {
        x = y % MOD;
        if (x < 0) x += MOD;
    }

    mint& operator+=(const mint& m) {
        x += m.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& m) {
        x -= m.x;
        if (x < 0) x += MOD;
        return *this;
    }
    mint& operator*=(const mint& m) {
        x = (long long)x * m.x % MOD;
        return *this;
    }
    mint& operator/=(const mint& m) {
        return *this *= inverse(m);
    }
    mint operator+(const mint& m) const {
        return mint(*this) += m;
    }
    mint operator-(const mint& m) const {
        return mint(*this) -= m;
    }
    mint operator*(const mint& m) const {
        return mint(*this) *= m;
    }
    mint operator/(const mint& m) const {
        return mint(*this) /= m;
    }
    mint operator-() const {
        return -x;
    }

    friend mint inverse(const mint& m) {
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

    friend istream& operator>>(istream& is, mint& m) {
        long long t;
        is >> t;
        m = t;
        return is;
    }
    friend ostream& operator<<(ostream& os, const mint& m) {
        return os << m.x;
    }
    int to_int() const {
        return x;
    }
};

mint operator+(long long x, const mint& m) {
    return mint(x) + m;
}
mint operator-(long long x, const mint& m) {
    return mint(x) - m;
}
mint operator*(long long x, const mint& m) {
    return mint(x) * m;
}
mint operator/(long long x, const mint& m) {
    return mint(x) / m;
}

mint pow(mint m, long long k) {
    mint res = 1;
    for (; k > 0; k >>= 1, m *= m)
        if (k & 1) res *= m;
    return res;
}

class Eratosthenes_sieve {
    vector<bool> er;
    vector<int> p;

  public:
    Eratosthenes_sieve(int n): er(n + 1, true) {
        if (n >= 0) er[0] = false;
        if (n >= 1) er[1] = false;
        for (int i = 2; i * i <= n; i++)
            if (er[i])
                for (int j = i * i; j <= n; j += i) er[j] = false;
        rep (i, n + 1)
            if (er[i]) p.emplace_back(i);
    }

    vector<int> primes() const {
        return p;
    }

    bool is_prime(int a) const {
        assert(a <= (int)er.size() - 1);
        return a >= 0 && er[a];
    }
};

const int M = sqrt(10000000); // 446
Eratosthenes_sieve E(M);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep (i, n) cin >> a[i];

    vector<mint> ans(n, 1);
    vector<int> c(n), cuml(n + 1), cumr(n + 1);
    rep (p, 2, M + 1) {
        if (!E.is_prime(p)) continue;

        bool b = false;
        rep (i, n) c[i] = 0;
        rep (i, n) {
            while (a[i] % p == 0) {
                a[i] /= p;
                c[i]++;
                b = true;
            }
        }
        if (!b) continue;

        auto f = [&](vector<int> a, vector<int>& cum) {
            rep (i, n) cum[i + 1] = max(cum[i], a[i]);
        };
        rep (i, n + 1) cuml[i] = cumr[i] = 0;
        f(c, cuml);
        reverse(all(c));
        f(c, cumr);
        reverse(all(c));
        rep (i, n) {
            int e = max(cuml[i], cumr[n - i - 1]);
            ans[i] *= pow(mint(p), e);
        }
    }

    mint prod = 1;
    map<int, int> H;
    rep (i, n) {
        if (a[i] == 1) continue;
        if (H[a[i]] == 0) {
            prod *= a[i];
        }
        ++H[a[i]];
    }
    rep (i, n) {
        if (a[i] == 1 || H[a[i]] >= 2) {
            ans[i] *= prod;
        }
        else {
            ans[i] *= prod / a[i];
        }
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    rep (_, t) solve();
    return 0;
}
