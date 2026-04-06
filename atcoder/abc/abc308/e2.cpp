#include <bits/stdc++.h>

#define _overload4(a, b, c, d, e, ...) e
#define _overload5(a, b, c, d, e, f, ...) f
#define _rep1(n) for (int _ = 0; _ < (n); ++_)
#define _rep2(i, n) for (int i = 0; i < (n); ++i)
#define _rep3(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep4(i, a, b, c) for (int i = (a); i < (b); i+=(c))
#define rep(...) _overload4(__VA_ARGS__, _rep4, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define _show1(a) { std::clog << #a << " = " << a << endl; }
#define _show2(a, ...) { std::clog << #a << " = " << a << ", "; _show1(__VA_ARGS__); }
#define _show3(a, ...) { std::clog << #a << " = " << a << ", "; _show2(__VA_ARGS__); }
#define _show4(a, ...) { std::clog << #a << " = " << a << ", "; _show3(__VA_ARGS__); }
#define _show5(a, ...) { std::clog << #a << " = " << a << ", "; _show4(__VA_ARGS__); }
#define show(...) _overload5(__VA_ARGS__, _show5, _show4, _show3, _show2, _show1)(__VA_ARGS__)

template<class C>
long ssize(const C& c) { return size(c); }  // workaround until C++20

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

using namespace std;

int mex(int a, int b, int c) {
    int x;
    for (x = 0; x == a || x == b || x == c; x++);
    return x;
}

long solve(const string& s) { // count "MEX" as a subsequence
    int n = ssize(s);
    vector dp(n + 1, array<long, 3>());
    rep(j, 3) dp[0][j] = 0;
    rep(i, n) {
        rep(j, 3) dp[i + 1][j] = dp[i][j];
        if (s[i] == 'M') dp[i + 1][0] += 1;
        if (s[i] == 'E') dp[i + 1][1] += dp[i][0];
        if (s[i] == 'X') dp[i + 1][2] += dp[i][1];
    }
    return dp[n][2];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(11);

    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    string s; cin >> s;

    long ans = 0;
    rep(m, 3) rep(e, 3) rep(x, 3) {
        string t;
        rep(i, n) {
            if (s[i] == 'M' && a[i] == m) t += 'M';
            if (s[i] == 'E' && a[i] == e) t += 'E';
            if (s[i] == 'X' && a[i] == x) t += 'X';
        }
        ans += solve(t) * mex(m, e, x);
    }
    cout << ans << endl;

    return 0;
}
