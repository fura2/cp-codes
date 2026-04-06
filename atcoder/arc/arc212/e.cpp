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

mint factorial(int n) {
    static vector<mint> memo = {1};
    if (memo.size() <= n) {
        int k = memo.size();
        memo.resize(n + 1);
        for (; k <= n; k++) memo[k] = memo[k - 1] * k;
    }
    return memo[n];
}

mint factorial_inverse(int n) {
    static vector<mint> memo = {1};
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
        rep (i, k) res *= n - i;
        return res;
    }
}

template<class T>
class Cartesian_tree {
    vector<T> a;
    int rt;
    vector<int> p, l, r;

  public:
    Cartesian_tree(const vector<T>& a = {}) {
        build(a);
    }

    void build(const vector<T>& a) {
        this->a = a;
        int n = a.size();
        rt = 0;
        p.assign(n, -1);
        l.assign(n, -1);
        r.assign(n, -1);

        for (int u = 1; u < n; u++) {
            int v = u - 1;
            bool top = false;
            while (a[v] > a[u]) {
                if (p[v] == -1) {
                    top = true;
                    break;
                }
                v = p[v];
            }
            if (top) {
                p[v] = u;
                l[u] = v;
                rt = u;
            }
            else {
                p[u] = v;
                if (r[v] != -1) p[r[v]] = u;
                l[u] = r[v];
                r[v] = u;
            }
        }
    }
    const T& operator[](int u) const {
        return a[u];
    }
    int root() const {
        return rt;
    }
    int parent(int u) const {
        return p[u];
    }
    int left(int u) const {
        return l[u];
    }
    int right(int u) const {
        return r[u];
    }
};

Cartesian_tree<int> T;

// u を根とする部分木を全部消す方法の数
// 頂点 u は元の数列の区間 [a, b) に対応
// bl: 1 回以上左に降りたかどうか
// br: 1 回以上右に降りたかどうか
mint dfs(int u, int a, int b, bool bl, bool br) {
    if (u == -1) return 1;

    mint xl = dfs(T.left(u), a, u, true, br);
    mint xr = dfs(T.right(u), u + 1, b, bl, true);

    // 左右の部分木それぞれの消し方を固定したときの, 根, 左, 右の並べ替えの分
    mint c = 0;
    int nl = u - a, nr = b - (u + 1);
    if (bl) { // 右を全部消したら根も消せる
        c += choose(b - a, nl);
    }
    if (br) { // 左を全部消したら根も消せる
        c += choose(b - a, nr);
    }
    if (bl && br) {
        c -= choose(b - a - 1, nl); // 重複カウント分
    }

    return c * xl * xr;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep (i, n) cin >> p[i], p[i]--, p[i] *= -1;

    T.build(p);

    int r = T.root();
    mint ans = dfs(T.left(r), 0, r, true, false) * dfs(T.right(r), r + 1, n, false, true);
    ans *= choose(n - 1, r); // 左右それぞれの部分木の結果の並べ替えの分
    cout << ans << endl;

    return 0;
}
