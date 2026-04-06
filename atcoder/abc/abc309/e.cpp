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

template<class G>
class Fenwick_tree_dual {
    vector<G> a;
public:
    Fenwick_tree_dual(int n = 0) { build(n); }
    Fenwick_tree_dual(const vector<G>& a) { build(a); }
    void build(int n) {
        a.assign(n, G{});
    }
    void build(const vector<G>& a) {
        this->a = a;
        for (int i = 1; i <= a.size(); i++) if (i + (i & -i) <= a.size()) (this->a)[i - 1] -= (this->a)[i + (i & -i) - 1];
    }
    void add(int l, int r, const G& val) {
        if (l == 0) {
            for (; r > 0; r -= r & -r) a[r - 1] += val;
            return;
        }
        add(0, r, val);
        add(0, l, -val);
    }
    G get(int i)const {
        G res{};
        for (i++; i <= a.size(); i += i & -i) res += a[i - 1];
        return res;
    }
};

using graph = vector<vector<int>>;

void add_directed_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
}

int main() {
    int n, m; cin >> n >> m;
    graph T(n);
    rep(v, 1, n) {
        int u; cin >> u; u--;
        add_directed_edge(T, u, v);
    }
    map<int, int> sum;
    vector<int> x(m), y(m);
    rep(i, m) {
        cin >> x[i] >> y[i]; x[i]--;
        sum[x[i]] = max(sum[x[i]], y[i]);
    }

    Fenwick_tree_dual<int> F(600001);
    int ans = 0;
    auto dfs = [&](auto&& dfs, int u, int dep) -> void {
        if (sum.count(u) > 0) {
            int y = sum[u];
            F.add(dep, dep + y + 1, 1);
        }

        if (F.get(dep) > 0) ans++;
        for (int v : T[u]) {
            dfs(dfs, v, dep + 1);
        }

        if (sum.count(u) > 0) {
            int y = sum[u];
            F.add(dep, dep + y + 1, -1);
        }
    };
    dfs(dfs, 0, 0);

    cout << ans << endl;

    return 0;
}
