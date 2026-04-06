#include <bits/stdc++.h>

using namespace std;

class mint {
    static const int MOD = 998244353;
    int x;

  public:
    mint(): x(0) {}
    mint(long long y) {
        x = y % MOD;
        if (x < 0) x += MOD;
    }

    mint& operator+=(const mint& m) {
        x += m.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& m) {
        x -= m.x;
        if (x < 0) x += MOD;
        return *this;
    }
    mint& operator*=(const mint& m) {
        x = (long long)x * m.x % MOD;
        return *this;
    }
    mint& operator/=(const mint& m) {
        return *this *= inverse(m);
    }
    mint operator+(const mint& m) const {
        return mint(*this) += m;
    }
    mint operator-(const mint& m) const {
        return mint(*this) -= m;
    }
    mint operator*(const mint& m) const {
        return mint(*this) *= m;
    }
    mint operator/(const mint& m) const {
        return mint(*this) /= m;
    }
    mint operator-() const {
        return -x;
    }

    friend mint inverse(const mint& m) {
        int a = m.x, b = MOD, u = 1, v = 0;
        while (b > 0) {
            int t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return u;
    }

    friend istream& operator>>(istream& is, mint& m) {
        long long t;
        is >> t;
        m = t;
        return is;
    }
    friend ostream& operator<<(ostream& os, const mint& m) {
        return os << m.x;
    }
    int to_int() const {
        return x;
    }
};

mint operator+(long long x, const mint& m) {
    return mint(x) + m;
}
mint operator-(long long x, const mint& m) {
    return mint(x) - m;
}
mint operator*(long long x, const mint& m) {
    return mint(x) * m;
}
mint operator/(long long x, const mint& m) {
    return mint(x) / m;
}

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
        for (k = 1; k <= a.size(); k <<= 1);
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= a.size() && a[x + k - 1] < val) val -= a[x + k - 1], x += k;
        return x;
    }
    int upper_bound(G val) const {
        if (val < G{}) return 0;
        int x = 0, k;
        for (k = 1; k <= a.size(); k <<= 1);
        for (k >>= 1; k > 0; k >>= 1)
            if (x + k <= a.size() && !(val < a[x + k - 1])) val -= a[x + k - 1], x += k;
        return x;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    // 「最初に上がって、途中はどうでもよくて、最後に下がる」ものを数えればいい
    // p の部分列を a_1, ..., a_k と書くと、
    // l[i] = (a_2 == p[i] と選ぶときに候補となる a_1 の個数)
    // r[i] = (a_{k-1}} == p[i] と選ぶときに候補となる a_k の個数)
    vector<int> l(n), r(n);
    Fenwick_tree<int> CL(n), CR(n);
    for (int i = 0; i < n; i++) {
        l[i] = CL.sum(0, p[i]);
        CL.add(p[i], 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        r[i] = CR.sum(0, p[i]);
        CR.add(p[i], 1);
    }

    // O(n^2) solution
    // mint ans = 0;
    // for (int i = 0; i < n; i++) {
    //     mint tmp = r[i];
    //     for (int j = i + 1; j < n; j++) {
    //         tmp += r[j] * (1 << (j - i - 1));
    //     }
    //     ans += l[i] * tmp;
    // }

    vector<mint> f(n);
    for (int i = n - 2; i >= 0; i--) {
        f[i] = 2 * f[i + 1] + r[i];
    }
    mint ans = 0;
    for (int i = 0; i < n; i++) {
        mint tmp = r[i];
        if (i < n - 1) {
            tmp += f[i + 1];
        }
        ans += l[i] * tmp;
    }
    cout << ans << endl;

    return 0;
}
