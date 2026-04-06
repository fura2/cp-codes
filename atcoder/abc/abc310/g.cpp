#include "template.hpp"

class mint {
    static const int MOD = 998244353;
    int x;
public:
    mint():x(0) {}
    mint(long long y) { x = y % MOD; if (x < 0) x += MOD; }

    mint& operator+=(const mint& m) { x += m.x; if (x >= MOD) x -= MOD; return *this; }
    mint& operator-=(const mint& m) { x -= m.x; if (x < 0) x += MOD; return *this; }
    mint& operator*=(const mint& m) { x = (long long)x * m.x % MOD; return *this; }
    mint& operator/=(const mint& m) { return *this *= inverse(m); }
    mint operator+(const mint& m)const { return mint(*this) += m; }
    mint operator-(const mint& m)const { return mint(*this) -= m; }
    mint operator*(const mint& m)const { return mint(*this) *= m; }
    mint operator/(const mint& m)const { return mint(*this) /= m; }
    mint operator-()const { return -x; }

    friend mint inverse(const mint& m) {
        int a = m.x, b = MOD, u = 1, v = 0;
        while (b > 0) { int t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        return u;
    }

    friend istream& operator>>(istream& is, mint& m) { long long t; is >> t; m = t; return is; }
    friend ostream& operator<<(ostream& os, const mint& m) { return os << m.x; }
    int to_int()const { return x; }
};

mint operator+(long long x, const mint& m) { return mint(x) + m; }
mint operator-(long long x, const mint& m) { return mint(x) - m; }
mint operator*(long long x, const mint& m) { return mint(x) * m; }
mint operator/(long long x, const mint& m) { return mint(x) / m; }

class endomorphism_monoid {
    vector<int> f;
public:
    endomorphism_monoid() {}
    endomorphism_monoid(const vector<int>& f):f(f) {}
    endomorphism_monoid operator*(const endomorphism_monoid& a)const {
        int n = f.size(), m = a.f.size();
        int k = max(n, m);
        vector<int> res(k);
        rep(i, k) {
            int x = (i < m ? a.f[i] : i);
            res[i] = (x < n ? f[x] : x);
        }
        return res;
    }
    int operator[](int i)const { return i < ssize(f) ? f[i] : i; }
};

vector<mint> operator*(const endomorphism_monoid& a, const vector<mint>& b) {
    int n = b.size();
    vector<mint> res(n);
    rep(i, n) res[a[i]] += b[i];
    return res;
}

vector<mint> operator+(const vector<mint>& b1, const vector<mint>& b2) {
    int n = b1.size();
    vector<mint> res(n);
    rep(i, n) res[i] = b1[i] + b2[i];
    return res;
}

vector<mint> operator-(const vector<mint>& b1, const vector<mint>& b2) {
    int n = b1.size();
    vector<mint> res(n);
    rep(i, n) res[i] = b1[i] - b2[i];
    return res;
}

int n;

class affine_monoid {
    endomorphism_monoid a;
    vector<mint> b;
public:
    affine_monoid():a(), b(n) {}
    affine_monoid(const endomorphism_monoid& a, const vector<mint>& b):a(a), b(b) {}
    affine_monoid operator*(const affine_monoid& x)const {
        return { x.a * a, x.a * b + x.b };
    }
    pair<endomorphism_monoid&, vector<mint>&> get() { return { a, b }; }
    pair<const endomorphism_monoid&, const vector<mint>&> get()const { return { a, b }; }
    vector<mint> eval(const vector<mint>& x)const { return a * x + b; }
};

template<class M>
M pow(M f, long long k) {
    M res;
    for (; k > 0; k >>= 1) {
        if (k & 1) res = res * f;
        f = f * f;
    }
    return res;
}

int main() {
    lint k; cin >> n >> k;
    vector<int> a(n);
    vector<mint> b(n);
    rep(i, n) cin >> a[i], a[i]--;
    rep(i, n) cin >> b[i];

    rep(i, n) b[i] /= k;

    affine_monoid f(a, b);
    vector<mint> ans = pow(f, k).eval(b) - b;
    rep(i, n) cout << ans[i] << " \n"[i < n - 1 ? 0 : 1];

    return 0;
}
