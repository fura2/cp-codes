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

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(11);

    multiset<int> S, X;
    int q; cin >> q;
    rep(q) {
        int type; cin >> type;
        if (type == 1) {
            int x; cin >> x;
            auto it = S.insert(x);
            int l = -1, r = -1;
            if (it != S.begin()) {
                l = *prev(it);
                X.insert(x ^ l);
            }
            if (next(it) != S.end()) {
                r = *next(it);
                X.insert(x ^ r);
            }
            if (l != -1 && r != -1) {
                X.erase(X.find(l ^ r));
            }
        }
        else if (type == 2) {
            int x; cin >> x;
            auto it = S.find(x);
            int l = -1, r = -1;
            if (it != S.begin()) {
                l = *prev(it);
                X.erase(X.find(x ^ l));
            }
            if (next(it) != S.end()) {
                r = *next(it);
                X.erase(X.find(x ^ r));
            }
            if (l != -1 && r != -1) {
                X.insert(l ^ r);
            }
            S.erase(it);
        }
        else {
            cout << *X.begin() << "\n";
        }
    }

    return 0;
}
