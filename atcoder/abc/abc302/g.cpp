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

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]--;

    vector<int> from(n);
    {
        int cnt[4] = {};
        rep(i, n) cnt[a[i]]++;
        int i = 0;
        rep(v, 4) rep(cnt[v]) from[i] = v, i++;
    }

    int A[4][4] = {};
    rep(i, n) A[from[i]][a[i]]++;

    int ans = 0;
    // cycle of length 1
    rep(i, 4) {
        A[i][i] = 0;
    }
    // cycle of length 2
    rep(i, 4) rep(j, 4) {
        if (i != j) {
            int v = min(A[i][j], A[j][i]);
            A[i][j] -= v;
            A[j][i] -= v;
            ans += v;
        }
    }
    // cycle of length 3
    rep(i, 4) rep(j, 4) rep(k, 4) {
        if (set({ i, j, k }).size() == 3) {
            int v = min({ A[i][j], A[j][k], A[k][i] });
            A[i][j] -= v;
            A[j][k] -= v;
            A[k][i] -= v;
            ans += 2 * v;
        }
    }
    // cycle of length 4
    rep(i, 4) rep(j, 4) rep(k, 4) rep(l, 4) {
        if (set({ i, j, k, l }).size() == 4) {
            int v = min({ A[i][j], A[j][k], A[k][l], A[l][i] });
            A[i][j] -= v;
            A[j][k] -= v;
            A[k][l] -= v;
            A[l][i] -= v;
            ans += 3 * v;
        }
    }

    rep(i, 4) rep(j, 4) assert(A[i][j] == 0);
    cout << ans << endl;

    return 0;
}
