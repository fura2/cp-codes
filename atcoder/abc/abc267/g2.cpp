// inclusion-exclusion approach O(n^2)
// https://atcoder.jp/contests/abc267/editorial/4769

#include <bits/stdc++.h>

#define _overload4(a, b, c, d, e, ...) e
#define _overload5(a, b, c, d, e, f, ...) f
#define _rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define _rep3(i, a, b) _rep4(i, a, b, 1)
#define _rep2(i, n) _rep3(i, 0, n)
#define _rep1(n) for (int _ = 0; _ < (n); ++_)
#define _rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define _rrep3(i, a, b) _rrep4(i, a, b, 1)
#define _rrep2(i, n) _rrep3(i, 0, n)

#define rep(...) _overload4(__VA_ARGS__, _rep4, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define rrep(...) _overload4(__VA_ARGS__, _rrep4, _rrep3, _rrep2)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()

#define _show1(a) { std::clog << #a << " = " << a << endl; }
#define _show2(a, ...) { std::clog << #a << " = " << a << ", "; _show1(__VA_ARGS__); }
#define _show3(a, ...) { std::clog << #a << " = " << a << ", "; _show2(__VA_ARGS__); }
#define _show4(a, ...) { std::clog << #a << " = " << a << ", "; _show3(__VA_ARGS__); }
#define _show5(a, ...) { std::clog << #a << " = " << a << ", "; _show4(__VA_ARGS__); }
#define show(...) _overload5(__VA_ARGS__, _show5, _show4, _show3, _show2, _show1)(__VA_ARGS__)

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

mint pow(mint m, long long k) {
    mint res = 1;
    for (; k > 0; k >>= 1, m *= m) if (k & 1) res *= m;
    return res;
}

mint factorial(int n) {
    static vector<mint> memo = { 1 };
    if (memo.size() <= n) {
        int k = memo.size();
        memo.resize(n + 1);
        for (; k <= n; k++) memo[k] = memo[k - 1] * k;
    }
    return memo[n];
}

mint factorial_inverse(int n) {
    static vector<mint> memo = { 1 };
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
        rep(i, k) res *= n - i;
        return res;
    }
}

mint multichoose(int n, int k, int type = 0) {
    return choose(n + k - 1, k, type);
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));

    // f(i) = ({1, 2, ..., n} の順列を次の条件を満たす i 個の (空でもいい) 連続部分列に分ける方法の個数)
    //        条件: 各連続部分列 (i_1, ..., i_k) は鎖である (i.e., a_{i_1} < ... < a_{i_k})
    // 例: a = (1a, 1b, 2) のとき
    //     f(1) = |{}| = 0
    //     f(2) = |{((1a), (1b,2)), ((1a,2), (1b)), ((1b), (1a,2)), ((1b,2), (1a))}| = 4
    //     f(3) = |{((), (1a), (1b,2)), ...}| = 18
    vector<mint> f(n + 1);
    {
        map<int, int> hist;
        rep(i, n) ++hist[a[i]];
        rep(i, 1, n + 1) {
            f[i] = 1;
            for (auto [k, v] : hist) rep(j, v) f[i] *= i - j;
        }
    }

    // g(i) = ({1, 2, ..., n} の順列を i 個の空でない鎖に分ける方法の個数)
    // 例: a = (1a, 1b, 2) のとき
    //     g(1) = f(1) = 0
    //     g(2) = f(2) = 8
    //     g(3) = |{((1a), (1b), (2)), ...}| = 6
    vector<mint> g(n + 1);
    rep(i, n + 1) {
        rrep(j, i + 1) {
            g[i] += ((i - j) % 2 == 0 ? 1 : -1) * choose(i, j) * f[j];
        }
    }

    // h[i] = ({1, 2, ..., n} の順列を i 個の極大な鎖に分ける方法の個数)
    vector<mint> h(n + 1);
    rep(i, n + 1) {
        h[i] = g[i];
        // g(i) で数え上げられた i 個の鎖 c_1, ..., c_i に対して、
        // a_{t(c_k)} >= a_{s(c_{k+1})} なる k の個数を j とする。
        // もちろん、a_{t(c_k)} < a_{s(c_{k+1})} なる k の個数は i-j になる。
        // すべての鎖が極大であることは j = i と同値。
        // j < i のときは、a_{t(c_k)} < a_{s(c_{k+1})} なるすべての k に対して
        // c_k と c_{k+1} を連結することで、j 個の極大な鎖のケース (h(j) で数えるもの) に帰着する。
        // 逆向きの対応は、h(j) で数え上げられる j 個の極大な鎖に対して
        // 各鎖の終端以外の n-j 箇所のうち i-j 箇所を切ることで得られる。
        rep(j, i) h[i] -= choose(n - j, i - j) * h[j];
    }

    cout << h[n - k] << endl;

    return 0;
}
