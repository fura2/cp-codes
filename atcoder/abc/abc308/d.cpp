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

const int dx[] = { 0, -1, 0, 1 }, dy[] = { 1, 0, -1, 0 };

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(11);

    int h, w; cin >> h >> w;
    vector<string> B(h);
    rep(i, h) cin >> B[i];

    char f[128];
    f['s'] = 'n';
    f['n'] = 'u';
    f['u'] = 'k';
    f['k'] = 'e';
    f['e'] = 's';

    bool vis[500][500] = {};
    queue<pair<int, int>> Q;
    if (B[0][0] == 's') {
        vis[0][0] = true;
        Q.emplace(0, 0);
    }
    while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        rep(k, 4) {
            int x2 = x + dx[k], y2 = y + dy[k];
            if (0 <= x2 && x2 < h && 0 <= y2 && y2 < w && !vis[x2][y2] && B[x2][y2] == f[B[x][y]]) {
                vis[x2][y2] = true;
                Q.emplace(x2, y2);
            }
        }
    }
    yesno(vis[h - 1][w - 1]);

    return 0;
}
