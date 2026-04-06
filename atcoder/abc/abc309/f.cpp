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
#define all(v) begin(v), end(v)

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

bool solve(vector<tuple<int, int, int>> a, vector<tuple<int, int, int>> b) {
    int n = size(a);
    sort(all(a));
    sort(all(b));

    segment_tree<max_monoid<int>> S(3 * n);

    int pos = n - 1;
    rrep(i, n) {
        auto [ah, aw, ad] = a[i];

        while (pos != -1 && get<0>(b[pos]) > ah) {
            auto [bh, bw, bd] = b[pos];
            S.update(bw, S[bw] * bd);
            pos--;
        }

        if (S.product(aw + 1, 3 * n).get() > ad) {
            return true;
        }
    }
    return false;
}

int main() {
    int n; cin >> n;
    vector<tuple<int, int, int>> a(n);
    rep(i, n) {
        int h, w, d; cin >> h >> w >> d;
        a[i] = { h, w, d };
    }

    vector<int> X;
    for (auto [h, w, d] : a) {
        X.emplace_back(h);
        X.emplace_back(w);
        X.emplace_back(d);
    }
    sort(all(X));
    X.erase(unique(all(X)), end(X));
    for (auto& [h, w, d] : a) {
        h = lower_bound(all(X), h) - begin(X);
        w = lower_bound(all(X), w) - begin(X);
        d = lower_bound(all(X), d) - begin(X);
    }

    int p[3] = { 0, 1, 2 };
    do {
        auto b = a;
        rep(i, n) {
            int x[3];
            tie(x[0], x[1], x[2]) = a[i];
            b[i] = { x[p[0]], x[p[1]], x[p[2]] };
        }
        if (solve(a, b)) {
            yes();
            return 0;
        }
    } while (next_permutation(all(p)));
    no();

    return 0;
}
