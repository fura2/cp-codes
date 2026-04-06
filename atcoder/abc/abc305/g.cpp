#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

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

template<class R>
class matrix {
    vector<vector<R>> a;
public:
    matrix(int n):a(n, vector<R>(n)) {}
    matrix(int m, int n):a(m, vector<R>(n)) {}

    matrix& operator+=(const matrix& A) {
        assert(h() == A.h() && w() == A.w());
        int m = h(), n = w();
        rep(i, m) rep(j, n) (*this)[i][j] += A[i][j];
        return *this;
    }
    matrix& operator-=(const matrix& A) {
        assert(h() == A.h() && w() == A.w());
        int m = h(), n = w();
        rep(i, m) rep(j, n) (*this)[i][j] -= A[i][j];
        return *this;
    }
    matrix& operator*=(const matrix& A) {
        assert(w() == A.h());
        int m = h(), n = w(), l = A.w();
        matrix B(m, l);
        rep(i, m) rep(j, l) rep(k, n) B[i][j] += (*this)[i][k] * A[k][j];
        swap(*this, B);
        return *this;
    }
    matrix operator+(const matrix& A)const { return matrix(*this) += A; }
    matrix operator-(const matrix& A)const { return matrix(*this) -= A; }
    matrix operator*(const matrix& A)const { return matrix(*this) *= A; }
    const vector<R>& operator[](int i)const { return a[i]; }
    vector<R>& operator[](int i) { return a[i]; }

    vector<R> operator*(const vector<R>& v)const {
        assert(w() == v.size());
        int m = h(), n = w();
        vector<R> res(m);
        rep(i, m) rep(j, n) res[i] += (*this)[i][j] * v[j];
        return res;
    }

    int h()const { return a.size(); }
    int w()const { return a.empty() ? 0 : a[0].size(); }

    static matrix identity(int n) {
        matrix I(n);
        rep(i, n) I[i][i] = R{ 1 };
        return I;
    }
};

template<class R>
matrix<R> pow(matrix<R> A, long long k) {
    assert(A.h() == A.w());
    matrix<R> B = matrix<R>::identity(A.h());
    for (; k > 0; k >>= 1) {
        if (k & 1) B *= A;
        A *= A;
    }
    return B;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    long long n;
    int m; cin >> n >> m;
    vector<string> s(m);
    rep(i, m) cin >> s[i];

    if (n <= 5) {
        mint res = 0;
        rep(S, 1 << n) {
            string t;
            rep(i, n) t += "ab"[S >> i & 1];
            bool ok = true;
            rep(i, m) if (t.find(s[i]) != string::npos) ok = false;
            if (ok) res += 1;
        }
        cout << res << endl;
        return 0;
    }

    matrix<mint> A(32, 32);
    rep(S, 1 << 5) {
        string t;
        rep(i, 5) t += "ab"[S >> i & 1];

        rep(c, 2) {
            string t2 = t + "ab"[c];
            bool ok = true;
            rep(i, m) if (t2.find(s[i]) != string::npos) ok = false;
            if (ok) {
                int T = 0;
                rep(i, 5) T |= (t2[i + 1] == 'a' ? 0 : 1) << i;
                A[S][T] = 1;
            }
        }
    }

    matrix<mint> B = pow(A, n - 5);
    mint ans = 0;
    rep(i, 32) rep(j, 32) ans += B[i][j];
    cout << ans << endl;

    return 0;
}
