#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
    static const int MOD = 1000000007;
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

using lint = long long;

template<class T> struct edge {
    int id, to;
    T wt;
    edge(int id, int to, const T& wt):id(id), to(to), wt(wt) {}
};
template<class T> using weighted_graph = vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G, int id, int u, int v, const T& wt) {
    G[u].emplace_back(id, v, wt);
    G[v].emplace_back(id, u, wt);
}

// cnt[u][c] = (u を根とする部分木について、u を端点とする重み c のパスの本数)
lint cnt[200000][2];
void dfs(const weighted_graph<int>& G, int u, int p) {
    cnt[u][0] = 1;
    cnt[u][1] = 0;
    for (const auto& e : G[u]) if (e.to != p) {
        dfs(G, e.to, u);
        cnt[u][0] += cnt[e.to][0 ^ e.wt];
        cnt[u][1] += cnt[e.to][1 ^ e.wt];
    }
};

lint dfs2(const weighted_graph<int>& G, int u, int p, pair<lint, lint> cum) {
    cum.first += cnt[u][0];
    cum.second += cnt[u][1];

    lint res = cum.second;
    for (const auto& e : G[u]) if (e.to != p) {
        auto cum2 = cum;
        cum2.first -= cnt[e.to][0 ^ e.wt];
        cum2.second -= cnt[e.to][1 ^ e.wt];
        if (e.wt == 1) swap(cum2.first, cum2.second);
        res += dfs2(G, e.to, u, cum2);
    }
    return res;
};

// 辺の重みが 0 or 1 のときの、すべてのパスの重みの総和
lint f(const weighted_graph<int>& G) {
    int n = G.size();
    rep(u, n) rep(c, 2) cnt[u][c] = 0;
    dfs(G, 0, -1);
    return dfs2(G, 0, -1, { 0, 0 });
}

int main() {
    int n; cin >> n;
    weighted_graph<int> G(n);
    vector<lint> costs(n - 1);
    rep(i, n - 1) {
        int u, v;
        lint cost; cin >> u >> v >> cost; u--; v--;
        add_undirected_edge(G, i, u, v, 0);
        costs[i] = cost;
    }

    mint ans = 0;
    rep(b, 60) {
        rep(u, n) for (auto& e : G[u]) {
            e.wt = bit(costs[e.id], b);
        }
        ans += mint(f(G)) * (1LL << b);
    }
    ans /= 2;
    cout << ans << endl;

    return 0;
}
