#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define show(x) { cout << #x << " = " << x << endl; }

using namespace std;

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        cout << e;
    }
    os << "}";
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e : v) {
        if (!first) os << ", ";
        first = false;
        cout << e;
    }
    os << "]";
    return os;
}

long balance(set<pair<long, int>>& S, set<pair<long, int>>& L, int k) {
    long res = 0;
    if (!S.empty() && !L.empty() && -L.rbegin()->first < -S.begin()->first) {
        res -= -L.rbegin()->first;
        S.insert(*--L.end());
        L.erase(--L.end());
    }
    while (L.size() < k) {
        res += -S.begin()->first;
        L.insert(*S.begin());
        S.erase(S.begin());
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, k, q; cin >> n >> k >> q;
    vector<long> a(n);

    set<pair<long, int>> S, L;
    rep(i, n) S.emplace(0, i);
    balance(S, L, k);

    long ans = 0;
    rep(_, q) {
        int x;
        long v; cin >> x >> v; x--;

        if (S.count({ -a[x], x }) > 0) {
            S.erase({ -a[x], x });
        }
        else {
            L.erase({ -a[x], x });
            ans -= a[x];
        }
        a[x] = v;
        S.emplace(-a[x], x);
        ans += balance(S, L, k);
        cout << ans << endl;
        // show(S);
        // show(L);
    }

    return 0;
}
