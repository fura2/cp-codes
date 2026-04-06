// greedy
// solution 1 of https://atcoder.jp/contests/abc218/editorial/2602

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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, nr; cin >> n >> nr;
    vector<long> a(n - 1);
    for (auto& e : a) cin >> e;

    if (nr > n / 2) nr = n - nr;

    vector<long> b(n);
    b[0] = a[0];
    for (int i = 1; i < n - 1; i++) b[i] = a[i - 1] + a[i];
    b[n - 1] = a[n - 2];

    set<int> Idx;
    rep(i, n) Idx.emplace(i);
    set<pair<long, int>> S;
    rep(i, n) S.emplace(-b[i], i);

    long ans = 0;
    rep(_, nr) {
        int i = S.begin()->second;

        ans += b[i];
        if (i == *Idx.begin()) {
            S.erase({ -b[i], i });
            Idx.erase(i);
            if (!S.empty()) {
                int r = *Idx.upper_bound(i);
                S.erase({ -b[r], r });
                Idx.erase(r);
            }
        }
        else if (i == *Idx.rbegin()) {
            S.erase({ -b[i], i });
            Idx.erase(i);
            if (!S.empty()) {
                int l = *--Idx.lower_bound(i);
                S.erase({ -b[l], l });
                Idx.erase(l);
            }
        }
        else {
            int l = *--Idx.lower_bound(i);
            int r = *Idx.upper_bound(i);
            S.erase({ -b[i], i });
            S.erase({ -b[l], l });
            S.erase({ -b[r], r });
            Idx.erase(l);
            Idx.erase(r);
            b[i] = b[l] + b[r] - b[i];
            S.emplace(-b[i], i);
        }
    }
    cout << ans << endl;

    return 0;
}
