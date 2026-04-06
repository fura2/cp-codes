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

template<class G>
class Fenwick_tree {
    vector<G> a;
public:
    Fenwick_tree(int n = 0) { build(n); }
    Fenwick_tree(const vector<G>& a) { build(a); }
    void build(int n) {
        a.assign(n, G{});
    }
    void build(const vector<G>& a) {
        this->a = a;
        for (int i = 1; i <= a.size(); i++) if (i + (i & -i) <= a.size()) (this->a)[i + (i & -i) - 1] += (this->a)[i - 1];
    }
    void add(int i, const G& val) {
        for (i++; i <= a.size(); i += i & -i) a[i - 1] += val;
    }
    G sum(int l, int r)const {
        if (l == 0) {
            G res{};
            for (; r > 0; r -= r & -r) res += a[r - 1];
            return res;
        }
        return sum(0, r) - sum(0, l);
    }
    int lower_bound(G val)const {
        if (!(G{} < val)) return 0;
        int x = 0, k;
        for (k = 1; k <= a.size(); k <<= 1);
        for (k >>= 1; k > 0; k >>= 1) if (x + k <= a.size() && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
        return x;
    }
    int upper_bound(G val)const {
        if (val < G{}) return 0;
        int x = 0, k;
        for (k = 1; k <= a.size(); k <<= 1);
        for (k >>= 1; k > 0; k >>= 1) if (x + k <= a.size() && !(val < a[x + k - 1])) val -= a[x + k - 1], x += k;
        return x;
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n, m; cin >> n >> m;
    vector a(n, vector<long>(m));
    rep(i, n) {
        rep(j, m) cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
    }

    vector<long> X(n * m);
    rep(i, n) rep(j, m) X[i * m + j] = a[i][j];
    sort(X.begin(), X.end());

    Fenwick_tree<long> F(n * m);

    long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        rep(j, m) {
            int idx = lower_bound(X.begin(), X.end(), a[i][j]) - X.begin();
            ans += (n - i - 1) * (j + 1) + F.sum(0, idx);
        }
        rep(j, m) {
            int idx = lower_bound(X.begin(), X.end(), a[i][j]) - X.begin();
            F.add(idx, 1);
        }
    }
    cout << ans << endl;

    return 0;
}
