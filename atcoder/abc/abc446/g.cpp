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

template<class G>
class Fenwick_tree {
    vector<G> a;

  public:
    Fenwick_tree(int n = 0) {
        build(n);
    }
    Fenwick_tree(const vector<G>& a) {
        build(a);
    }
    void build(int n) {
        a.assign(n, G{});
    }
    void build(const vector<G>& a) {
        this->a = a;
        for (int i = 1; i <= a.size(); i++)
            if (i + (i & -i) <= a.size()) (this->a)[i + (i & -i) - 1] += (this->a)[i - 1];
    }
    void add(int i, const G& val) {
        for (i++; i <= a.size(); i += i & -i) a[i - 1] += val;
    }
    G sum(int l, int r) const {
        if (l == 0) {
            G res{};
            for (; r > 0; r -= r & -r) res += a[r - 1];
            return res;
        }
        return sum(0, r) - sum(0, l);
    }
    int lower_bound(G val) const {
        if (!(G{} < val)) return 0;
        int x = 0, k;
        for (k = 1; k <= a.size(); k <<= 1);
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= a.size() && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
        return x;
    }
    int upper_bound(G val) const {
        if (val < G{}) return 0;
        int x = 0, k;
        for (k = 1; k <= a.size(); k <<= 1);
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= a.size() && !(val < a[x + k - 1])) val -= a[x + k - 1], x += k;
        return x;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep (i, n) cin >> a[i];

    vector pos(n + 1, vector<int>());
    rep (i, n) pos[a[i]].emplace_back(i);

    /*
    // O(n^2) DP
    // dp[i] = (a[0..i] の 221 部分列であって、末尾が a[i] であるようなものの個数)
    vector<mint> dp(n);
    rep (i, n) {
        int j = lower_bound(all(pos[a[i]]), i) - pos[a[i]].begin();
        if (j + 1 < a[i]) {
            continue;
        }
        else if (j + 1 == a[i]) {
            dp[i] += 1;
            int r = pos[a[i]][j - a[i] + 1];
            rep (k, r) dp[i] += dp[k];
        }
        else { // j + 1 > a[i]
            int l = pos[a[i]][j - a[i]] + 1;
            int r = pos[a[i]][j - a[i] + 1];
            rep (k, l, r) {
                dp[i] += dp[k];
            }
        }
    }
    cout << accumulate(all(dp), mint(0)) << endl;
    */

    // dp[i] = (a[0..i] の 221 部分列であって、末尾が a[i] であるようなものの個数)
    Fenwick_tree<mint> dp(n);
    rep (i, n) {
        int j = lower_bound(all(pos[a[i]]), i) - pos[a[i]].begin();
        if (j + 1 < a[i]) {
            continue;
        }
        else if (j + 1 == a[i]) {
            dp.add(i, 1);
            int r = pos[a[i]][j - a[i] + 1];
            dp.add(i, dp.sum(0, r));
        }
        else { // j + 1 > a[i]
            int l = pos[a[i]][j - a[i]] + 1;
            int r = pos[a[i]][j - a[i] + 1];
            dp.add(i, dp.sum(l, r));
        }
    }
    cout << dp.sum(0, n) << endl;

    return 0;
}
