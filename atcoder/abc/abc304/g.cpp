// solution described in the editorial video
// https://www.youtube.com/watch?v=6KVyDkYHb_A

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

int n, a[200000];
int tar;

int f2(int k, int l1, int r1, int l2, int r2);

// k ビット目以下だけを考えたとき、
// a_i xor a_j >= tar となるペア (i, j) を [l, r) から選んで最大いくつ作れるか
int f1(int k, int l, int r) {
    if (k == -1) {
        return (r - l) / 2;
    }

    if (l == r) {
        return 0;
    }

    int i = lower_bound(a + l, a + r, (a[l] & ~((1 << k) - 1)) | (1 << k)) - a;
    if (bit(tar, k) == 1) {
        return f2(k - 1, l, i, i, r);
    }
    else {
        if (i - l >= r - i) {
            int v = f1(k - 1, l, i);
            return (r - i) + min(v, ((i - l) - (r - i)) / 2);
        }
        else {
            int v = f1(k - 1, i, r);
            return (i - l) + min(v, ((r - i) - (i - l)) / 2);
        }
    }
}

// k ビット目以下だけを考えたとき、
// a_i xor a_j >= tar となるペア (i, j) を [l1, r1) と [l2, r2) から一つずつ選んで最大いくつ作れるか
int f2(int k, int l1, int r1, int l2, int r2) {
    if (k == -1) {
        return min(r1 - l1, r2 - l2);
    }

    if (l1 == r1 || l2 == r2) {
        return 0;
    }

    int i1 = lower_bound(a + l1, a + r1, (a[l1] & ~((1 << k) - 1)) | (1 << k)) - a;
    int i2 = lower_bound(a + l2, a + r2, (a[l2] & ~((1 << k) - 1)) | (1 << k)) - a;
    if (bit(tar, k) == 1) {
        return f2(k - 1, l1, i1, i2, r2) + f2(k - 1, i1, r1, l2, i2);
    }
    else {
        if (i1 - l1 >= r2 - i2 && r1 - i1 >= i2 - l2) { // [l2, r2) がすべてマッチすることが確定する場合
            return r2 - l2;
        }
        else if (i1 - l1 <= r2 - i2 && r1 - i1 <= i2 - l2) { // [l1, r1) がすべてマッチすることが確定する場合
            return r1 - l1;
        }
        else if (i1 - l1 >= r2 - i2 && r1 - i1 <= i2 - l2) { // [i1, r1), [i2, r2) がすべてマッチすることが確定する場合
            int v = f2(k - 1, l1, i1, l2, i2);
            return (r1 - i1) + (r2 - i2) + min({ v, (i2 - l2) - (r1 - i1), (i1 - l1) - (r2 - i2) });
        }
        else { // [l1, i1), [l2, i2) がすべてマッチすることが確定する場合
            int v = f2(k - 1, i1, r1, i2, r2);
            return (i1 - l1) + (i2 - l2) + min({ v, (r2 - i2) - (i1 - l1), (r1 - i1) - (i2 - l2) });
        }
    }
}

int main() {
    cin >> n;
    rep(i, 2 * n) cin >> a[i];

    sort(a, a + 2 * n);

    int lo = 0, hi = 1 << 30;
    while (hi - lo > 1) {
        int mi = (lo + hi) / 2;
        tar = mi;
        if (f1(29, 0, 2 * n) >= (n + 1) / 2) lo = mi;
        else hi = mi;
    }
    cout << lo << endl;

    return 0;
}
