// 各 i に対して「P[i:i+k] のうち小さいものX個が先頭に昇順で並んでいる」ような最大の X が求められればよい.
// X は二分探索で求められる.

// X == k なら P が答え.
// X < k のとき, i + X が最大になる P[i:i+k] (複数ある場合は i が最小のもの) について操作するのが最適.

#include "template.hpp"

template<class G>
class Fenwick_tree {
    vector<G> a;

  public:
    Fenwick_tree(int n = 0) {
        build(n);
    }
    Fenwick_tree(const vector<G>& a) {
        build(a);
    }
    void build(int n) {
        a.assign(n, G{});
    }
    void build(const vector<G>& a) {
        this->a = a;
        for (int i = 1; i <= a.size(); i++)
            if (i + (i & -i) <= a.size()) (this->a)[i + (i & -i) - 1] += (this->a)[i - 1];
    }
    void add(int i, const G& val) {
        for (i++; i <= a.size(); i += i & -i) a[i - 1] += val;
    }
    G sum(int l, int r) const {
        if (l == 0) {
            G res{};
            for (; r > 0; r -= r & -r) res += a[r - 1];
            return res;
        }
        return sum(0, r) - sum(0, l);
    }
    int lower_bound(G val) const {
        if (!(G{} < val)) return 0;
        int x = 0, k;
        for (k = 1; k <= a.size(); k <<= 1)
            ;
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= a.size() && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
        return x;
    }
    int upper_bound(G val) const {
        if (val < G{}) return 0;
        int x = 0, k;
        for (k = 1; k <= a.size(); k <<= 1)
            ;
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= a.size() && !(val < a[x + k - 1])) val -= a[x + k - 1], x += k;
        return x;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> P(n);
    rep (i, n) {
        cin >> P[i];
        P[i]--;
    }

    // nxt[i] = (P[i] < P[i+1] < ... < P[x] > P[x+1] なる x (存在しなければ n))
    vector<int> nxt(n);
    nxt[n - 1] = n;
    rrep (i, n - 1) {
        if (P[i] < P[i + 1]) {
            nxt[i] = nxt[i + 1];
        }
        else {
            nxt[i] = i + 1;
        }
    }

    int d_opt = -1, i_opt = n;
    Fenwick_tree<int> F(n);
    rep (i, k - 1) {
        F.add(P[i], 1);
    }
    rep (i, n - k + 1) {
        F.add(P[i + k - 1], 1);

        int lo = 0, hi = n - i + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            int idx = F.lower_bound(mid);
            bool ok = (nxt[i] - i >= mid and P[i + mid - 1] == idx);
            (ok ? lo : hi) = mid;
        }
        if (lo >= k) {
            rep (i, n) cout << P[i] + 1 << (i < n - 1 ? ' ' : '\n');
            return 0;
        }

        int d = i + lo;
        if (d_opt < d or (d_opt == d and i_opt > i)) {
            d_opt = d;
            i_opt = i;
        }

        F.add(P[i], -1);
    }

    sort(begin(P) + i_opt, begin(P) + i_opt + k);
    rep (i, n) cout << P[i] + 1 << (i < n - 1 ? ' ' : '\n');

    return 0;
}
