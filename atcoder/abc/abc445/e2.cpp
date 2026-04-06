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

constexpr int M = 1e7;
vector<bool> sieve(M + 1, true);
vector<int> pf(M + 1);

vector<mint> pinv(M + 1, 1); // mod inverse of primes

void precalc() {
    // Eratosthenes sieve
    sieve[0] = sieve[1] = false;
    iota(all(pf), 0);
    for (int p = 2; p * p <= M; p++) {
        if (!sieve[p]) continue;
        for (int x = 2 * p; x <= M; x += p) {
            sieve[x] = false;
            pf[x] = p;
        }
    }

    rep (p, 2, M + 1) {
        if (!sieve[p]) continue;
        pinv[p] /= p;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep (i, n) cin >> a[i];

    auto factorize = [&](int x) {
        vector<pair<int, int>> res;
        while (x > 1) {
            int p = pf[x], e = 0;
            do {
                x /= p;
                e++;
            } while (x % p == 0);
            res.emplace_back(p, e);
        }
        return res;
    };

    vector<vector<pair<int, int>>> pfs(n);
    rep (i, n) pfs[i] = factorize(a[i]);
    vector<int> ps;
    rep (i, n)
        for (auto [p, e]: pfs[i]) ps.emplace_back(p);
    sort(all(ps));
    ps.erase(unique(all(ps)), ps.end());

    auto update = [](pair<int, int>& top2, int x) {
        if (x >= top2.first) {
            top2.second = top2.first;
            top2.first = x;
        }
        else if (x >= top2.second) {
            top2.second = x;
        }
    };

    static pair<int, int> top2[M];
    for (auto p: ps) top2[p] = {0, 0};
    rep (i, n) {
        for (auto [p, e]: pfs[i]) update(top2[p], e);
    }

    mint prod = 1;
    for (auto p: ps) prod *= pow(mint(p), top2[p].first);

    rep (i, n) {
        mint ans = prod;
        for (auto [p, e]: pfs[i]) {
            if (top2[p].first == e && top2[p].second < e) {
                ans *= pow(pinv[p], top2[p].first - top2[p].second);
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    precalc();
    int t;
    cin >> t;
    rep (_, t) solve();
    return 0;
}
