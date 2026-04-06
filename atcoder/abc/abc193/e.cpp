#include <bits/stdc++.h>

#define _overload4(a, b, c, d, e, ...) e
#define _rep1(n) for (int _ = 0; _ < (n); ++_)
#define _rep2(i, n) for (int i = 0; i < (n); ++i)
#define _rep3(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep4(i, a, b, c) for (int i = (a); i < (b); i+=(c))
#define rep(...) _overload4(__VA_ARGS__, _rep4, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define show(x) { std::clog << #x << " = " << x << endl; }

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

template<class T>
T xgcd(T a, T b, T& x, T& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    T g = xgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void solve() {
    long x, y, p, q; cin >> x >> y >> p >> q;

    long ans = LONG_MAX;
    rep(i, y) {
        // find k >= 0 s.t. p + k*(p + q) = x + i (mod 2x + 2y)
        long a = p + q, b = 2 * x + 2 * y, c = x + i - p;
        long g = gcd(a, b);
        if (c % g != 0) continue;
        a /= g;
        b /= g;
        c /= g;

        long k, l;
        xgcd(a, b, k, l);
        k *= c;
        k %= b;
        if (k < 0) k += b;
        ans = min(ans, p + k * (p + q));
    }
    rep(i, q) {
        // find l >= 0 s.t. x + l*(2x + 2y) = p + i (mod p + q)
        long a = p + q, b = 2 * x + 2 * y, c = p + i - x;
        long g = gcd(a, b);
        if (c % g != 0) continue;
        a /= g;
        b /= g;
        c /= g;

        long k, l;
        xgcd(a, b, k, l);
        l *= c;
        l %= a;
        if (l < 0) l += a;
        ans = min(ans, x + l * (2 * x + 2 * y));
    }

    if (ans < LONG_MAX) cout << ans << "\n";
    else cout << "infinity\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(11);

    int t; cin >> t;
    rep(t) solve();

    return 0;
}
