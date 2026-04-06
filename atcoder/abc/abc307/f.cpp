#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define show(x) { std::cout << #x << " = " << x << endl; }

void yes(bool b) {
    std::cout << (b ? "Yes" : "No") << "\n";
}

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
        std::cout << e;
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
        std::cout << e;
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
        std::cout << e;
    }
    os << "]";
    return os;
}

using namespace std;

template<class T> struct edge {
    int to;
    T wt;
    edge(int to, const T& wt):to(to), wt(wt) {}
};
template<class T> using weighted_graph = vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G, int u, int v, const T& wt) {
    G[u].emplace_back(v, wt);
    G[v].emplace_back(u, wt);
}

template<class M>
class segment_tree {
    int n, sz;
    vector<M> seg;
public:
    segment_tree(int n = 0) { build(n); }
    template<class T>
    segment_tree(const vector<T>& a) { build(a); }

    void build(int n) {
        this->n = n;
        for (sz = 1; sz < n; sz <<= 1);
        seg.assign(2 * sz, M());
    }

    template<class T>
    void build(const vector<T>& a) {
        build(a.size());
        rep(i, a.size()) seg[sz + i] = a[i];
        for (int i = sz - 1; i > 0; i--) {
            seg[i] = seg[2 * i] * seg[2 * i + 1];
        }
    }

    const M& operator[](int i)const {
        return seg[sz + i];
    }

    void update(int i, const M& x) {
        i += sz;
        seg[i] = x;
        for (i >>= 1; i > 0; i >>= 1) seg[i] = seg[2 * i] * seg[2 * i + 1];
    }

    M product(int l, int r)const {
        M lcum, rcum;
        for (int a = l + sz, b = r + sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) lcum = lcum * seg[a++];
            if (b & 1) rcum = seg[--b] * rcum;
        }
        return lcum * rcum;
    }

    template<class N, class F>
    N operate(int l, int r, const F& f) {
        N lcum, rcum;
        for (int a = l + sz, b = r + sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) lcum = lcum * f(seg[a++]);
            if (b & 1) rcum = f(seg[--b]) * rcum;
        }
        return lcum * rcum;
    }

    template<class F>
    int max_right(int l, const F& f)const {
        if (l == n) return n;
        M cum;
        auto dfs = [&](auto&& dfs, int a, int b, int u) {
            if (a == b - 1) {
                cum = cum * seg[u];
                return f(cum) ? b : a;
            }

            int c = (a + b) / 2;
            if (c <= l) {
                return dfs(dfs, c, b, 2 * u + 1);
            }
            if (l <= a && f(cum * seg[u])) {
                cum = cum * seg[u];
                return b;
            }

            int idx = dfs(dfs, a, c, 2 * u);
            if (idx < c) return idx;
            return dfs(dfs, c, b, 2 * u + 1);
            };
        return min(dfs(dfs, 0, sz, 1), n);
    }

    template<class F>
    int min_left(int r, const F& f)const {
        if (r == 0) return 0;
        M cum;
        auto dfs = [&](auto&& dfs, int a, int b, int u) {
            if (a == b - 1) {
                cum = seg[u] * cum;
                return f(cum) ? a : b;
            }

            int c = (a + b) / 2;
            if (r <= c) {
                return dfs(dfs, a, c, 2 * u);
            }
            if (b <= r && f(seg[u] * cum)) {
                cum = seg[u] * cum;
                return a;
            }

            int idx = dfs(dfs, c, b, 2 * u + 1);
            if (idx > c) return idx;
            return dfs(dfs, a, c, 2 * u);
            };
        return dfs(dfs, 0, sz, 1);
    }
};

template<class T>
class max_monoid {
    T a;
public:
    max_monoid(const T& val = numeric_limits<T>::min()):a(val) {}
    max_monoid operator*(const max_monoid& x)const {
        return max(a, x.a);
    }
    T& get() { return a; }
    const T& get()const { return a; }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, m; cin >> n >> m;
    weighted_graph<long> G(n);
    rep(i, m) {
        int u, v;
        long c; cin >> u >> v >> c; u--; v--;
        add_undirected_edge(G, u, v, c);
    }
    int n0; cin >> n0;
    vector<int> V0(n0);
    rep(i, n0) cin >> V0[i], V0[i]--;
    int nr; cin >> nr;
    vector<long> r(nr);
    rep(i, nr) cin >> r[i];

    segment_tree<max_monoid<long>> seg(r);

    vector<pair<int, long>> d(n, make_pair(nr + 1, 0)); // (何日目, 残り感染距離)
    priority_queue<pair<pair<int, long>, int>> Q;
    for (auto u : V0) {
        d[u] = { 0, 0 };
        Q.push(make_pair(make_pair(0, 0), u));
    }
    while (!Q.empty()) {
        auto [p, u] = Q.top(); Q.pop();
        int i = -p.first;
        long rem = p.second;

        if (d[u] != make_pair(i, rem)) continue;

        for (const auto& e : G[u]) {
            int v = e.to;
            long cost = e.wt;
            if (cost <= rem) {
                if (i < d[v].first || (i == d[v].first && rem - cost > d[v].second)) {
                    d[v] = { i, rem - cost };
                    Q.push(make_pair(make_pair(-i, rem - cost), v));
                }
            }
            else {
                int idx = seg.max_right(i, [&](const max_monoid<long>& m) { return m.get() < cost; });
                int i2 = idx + 1;
                if (i2 <= nr) {
                    if (i2 < d[v].first || (i2 == d[v].first && r[idx] - cost > d[v].second)) {
                        d[v] = { i2, r[idx] - cost };
                        Q.push(make_pair(make_pair(-i2, r[idx] - cost), v));
                    }
                }
            }
        }
    }

    rep(u, n) {
        cout << (d[u].first > nr ? -1 : d[u].first) << "\n";
    }

    return 0;
}
