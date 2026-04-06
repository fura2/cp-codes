#include <bits/stdc++.h>

#define _overload4(a, b, c, d, e, ...) e
#define _overload5(a, b, c, d, e, f, ...) f
#define _rep4(i, a, b, c)  for (int i = (a); i < (b); i+=(c))
#define _rep3(i, a, b)     _rep4(i, a, b, 1)
#define _rep2(i, n)        _rep3(i, 0, n)
#define _rep1(n)           for (int _ = 0; _ < (n); ++_)
#define rep(...) _overload4(__VA_ARGS__, _rep4, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define _rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i-=(c))
#define _rrep3(i, a, b)    _rrep4(i, a, b, 1)
#define _rrep2(i, n)       _rrep3(i, 0, n)
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

int main() {
    vector<vector<long>> res(501);
    res[1] = { 1 };
    res[3] = { 2, 3, 6 };
    rep(n, 4, 501) {
        set<long> S(all(res[n - 1]));
        rep(i, ssize(res[n - 1])) {
            // 1/x = 1/A + 1/B if (A-x)(B-x) = x^2
            // Let a = A - x, b = B - x
            // Choose a and b such that a*b = x^2 and 1 <= a < b and making max(a, b) as small as possible
            long x = res[n - 1][i];
            long a_opt, b_opt;
            long ab_max = LONG_MAX;
            for (long a = 1; a < x; a++) if (x * x % a == 0) {
                long b = x * x / a;
                if (S.count(x + a) == 0 && S.count(x + b) == 0 && max(a, b) < ab_max) {
                    a_opt = a;
                    b_opt = b;
                    ab_max = max(a, b);
                }
            }
            if (ab_max < LONG_MAX) {
                res[n] = res[n - 1];
                res[n].erase(res[n].begin() + i);
                res[n].push_back(x + a_opt);
                res[n].push_back(x + b_opt);
                sort(all(res[n]));
                break;
            }
        }
    }

    int t; cin >> t;
    rep(t) {
        int n; cin >> n;
        yesno(n != 2);
        for (auto x : res[n]) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
