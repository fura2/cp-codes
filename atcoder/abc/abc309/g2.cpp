// solution by Hakone DP
// https://atcoder.jp/contests/abc309/editorial/6766

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define _overload4(a, b, c, d, e, ...) e
#define _overload5(a, b, c, d, e, f, ...) f
#define _overload6(a, b, c, d, e, f, g, ...) g

#define _rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define _rep3(i, a, b) _rep4(i, a, b, 1)
#define _rep2(i, n) _rep3(i, 0, n)
#define _rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) _overload4(__VA_ARGS__, _rep4, _rep3, _rep2, _rep1)(__VA_ARGS__)

#define _rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define _rrep3(i, a, b) _rrep4(i, a, b, 1)
#define _rrep2(i, n) _rrep3(i, 0, n)
#define rrep(...) _overload4(__VA_ARGS__, _rrep4, _rrep3, _rrep2)(__VA_ARGS__)

#define all(v) begin(v), end(v)

#define _show1(a) { std::clog << #a << " = " << a << endl; }
#define _show2(a, ...) { std::clog << #a << " = " << a << ", "; _show1(__VA_ARGS__); }
#define _show3(a, ...) { std::clog << #a << " = " << a << ", "; _show2(__VA_ARGS__); }
#define _show4(a, ...) { std::clog << #a << " = " << a << ", "; _show3(__VA_ARGS__); }
#define _show5(a, ...) { std::clog << #a << " = " << a << ", "; _show4(__VA_ARGS__); }
#define _show6(a, ...) { std::clog << #a << " = " << a << ", "; _show5(__VA_ARGS__); }
#define show(...) _overload6(__VA_ARGS__, _show6, _show5, _show4, _show3, _show2, _show1)(__VA_ARGS__)

template<typename T>
constexpr inline int bit(T x, unsigned int k) { return (x >> k) & 1; }

template<typename C>
long ssize(const C& c) { return std::size(c); }  // workaround until C++20

void yes() { std::cout << "Yes\n"; }
void no() { std::cout << "No\n"; }
void yesno(bool b) { std::cout << (b ? "Yes" : "No") << "\n"; }

template<class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "}";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e : v) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    os << "]";
    return os;
}

struct Setup {
    Setup() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(11);
    }
} _setup;

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

int main() {
    int n, m; cin >> n >> m;

    int popcnt[1 << 5] = {};
    rep(S, 1 << m) rep(k, m) if (bit(S, k)) popcnt[S]++;

    // dp[i][j][S][T] = (添字 {1,2,...,i} と値 {1,2,...,i} のマッチングであって,
    //                   マッチング済みのすべてのペア (a, b) に対して |a-b|>=m が満たされていて,
    //                   j 組がマッチング済みで,
    //                   添字 i, i-1, ..., i-m+2 のうちマッチング済みのものの集合が S で,
    //                   値 i, i-1, ..., i-m+2 のうちマッチング済みのものの集合が T であるようなものの個数)
    vector dp(n + 1, vector(n + 1, vector(1 << (m - 1), vector(1 << (m - 1), mint(0)))));
    dp[0][0][0][0] = 1;
    rep(i, n) {
        rep(j, i + 1) {
            int k = i - j; // 未使用の組の個数
            rep(S, 1 << (m - 1)) {
                rep(T, 1 << (m - 1)) {
                    int S2, T2;
                    // 添字 i+1 と値 <=i-m+1 をマッチングし、値 i+1 と値 <=i-m+1 をマッチングする
                    if (i >= m && j <= i - 1) {
                        S2 = (S | (1 << (m - 1))) >> 1;
                        T2 = (T | (1 << (m - 1))) >> 1;
                        dp[i + 1][j + 2][S2][T2] += (k - (m - 1 - popcnt[T])) * (k - (m - 1 - popcnt[S])) * dp[i][j][S][T];
                    }
                    // 添字 i+1 と値 <=i-m+1 をマッチングし、値 i+1 を保留にする
                    if (i >= m) {
                        S2 = (S | (1 << (m - 1))) >> 1;
                        T2 = T >> 1;
                        dp[i + 1][j + 1][S2][T2] += (k - (m - 1 - popcnt[T])) * dp[i][j][S][T];
                    }
                    // 添字 i+1 を保留にし, 値 i+1 を添字 <=i-m+1 とマッチングする
                    if (i >= m) {
                        S2 = S >> 1;
                        T2 = (T | (1 << (m - 1))) >> 1;
                        dp[i + 1][j + 1][S2][T2] += (k - (m - 1 - popcnt[S])) * dp[i][j][S][T];
                    }
                    // 添字 i+1 と値 i+1 を両方とも保留にする
                    S2 = S >> 1;
                    T2 = T >> 1;
                    dp[i + 1][j][S2][T2] += dp[i][j][S][T];
                }
            }
        }
    }

    cout << dp[n][n][(1 << (m - 1)) - 1][(1 << (m - 1)) - 1] << endl;

    return 0;
}
