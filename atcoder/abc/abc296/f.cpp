/*
操作後に A の添字を適当に振り直すことで, A は固定されていて B についての操作と思える.
このとき, 操作は相異なる i, j, k を任意に選んだときの (B_i, B_j, B_k) に対する巡回置換になる.
長さ 3 の巡回置換では置換の parity は変わらない.
逆に, 操作によって B の要素を任意に選んだ二つ以外は好きな位置に動かせるので, parity が一致するような任意の順列に変換できる.
*/

#include "template.hpp"

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

template<class T>
long long inversion_number(const vector<T>& a) {
    auto X = a;
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    long long res = 0;
    Fenwick_tree<int> F(X.size());
    rep(i, a.size()) {
        int x = lower_bound(X.begin(), X.end(), a[i]) - X.begin();
        res += F.sum(x + 1, X.size());
        F.add(x, 1);
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> A(n), B(n);
    rep(i, n) cin >> A[i], A[i]--;
    rep(i, n) cin >> B[i], B[i]--;

    {
        auto A2 = A, B2 = B;
        sort(all(A2));
        sort(all(B2));
        if (A2 != B2) {
            no();
            return 0;
        }
        rep(i, n - 1) if (A2[i] == A2[i + 1]) {
            yes();
            return 0;
        }
    }

    yesno(inversion_number(A) % 2 == inversion_number(B) % 2);

    return 0;
}
