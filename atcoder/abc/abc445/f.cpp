#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define impl_overload4(a, b, c, d, e, ...) e
#define impl_overload5(a, b, c, d, e, f, ...) f
#define impl_overload6(a, b, c, d, e, f, g, ...) g
#define impl_overload7(a, b, c, d, e, f, g, h, ...) h

// clang-format off
#define impl_rep4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define impl_rep3(i, a, b) impl_rep4(i, a, b, 1)
#define impl_rep2(i, n) impl_rep3(i, 0, n)
#define impl_rep1(n) for (int _ = 0; _ < (n); ++_)
#define rep(...) impl_overload4(__VA_ARGS__, impl_rep4, impl_rep3, impl_rep2, impl_rep1)(__VA_ARGS__)

#define impl_rrep4(i, a, b, c) for (int i = (b) - 1; i >= (a); i -= (c))
#define impl_rrep3(i, a, b) impl_rrep4(i, a, b, 1)
#define impl_rrep2(i, n) impl_rrep3(i, 0, n)
#define rrep(...) impl_overload4(__VA_ARGS__, impl_rrep4, impl_rrep3, impl_rrep2)(__VA_ARGS__)
// clang-format on

#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)

template<typename T>
constexpr int bit(T x, unsigned int k) {
    return (x >> k) & 1;
}

template<typename T>
constexpr bool chmax(T& a, const T& b) {
    return a < b ? a = b, true : false;
}
template<typename T>
constexpr bool chmin(T& a, const T& b) {
    return a > b ? a = b, true : false;
}

void yesno(bool b) {
    std::cout << (b ? "Yes" : "No") << "\n";
}
void yes() {
    yesno(true);
}
void no() {
    yesno(false);
}

struct Setup {
    Setup() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(11);
    }
} setup;

#ifdef LOCAL
#include "template_local.hpp"
#else
#define show(...) ((void)0)
#endif

using uint = unsigned int;
using lint = long long;
using ulint = unsigned long long;

using namespace std;

#endif // TEMPLATE_HPP

template<class R>
class matrix {
    vector<vector<R>> a;

  public:
    matrix(int n): a(n, vector<R>(n)) {}
    matrix(int m, int n): a(m, vector<R>(n)) {}

    matrix& operator+=(const matrix& A) {
        assert(h() == A.h() && w() == A.w());
        int m = h(), n = w();
        rep (i, m)
            rep (j, n) (*this)[i][j] += A[i][j];
        return *this;
    }
    matrix& operator-=(const matrix& A) {
        assert(h() == A.h() && w() == A.w());
        int m = h(), n = w();
        rep (i, m)
            rep (j, n) (*this)[i][j] -= A[i][j];
        return *this;
    }
    matrix& operator*=(const matrix& A) {
        assert(w() == A.h());
        int m = h(), n = w(), l = A.w();
        matrix B(m, l);
        rep (i, m)
            rep (j, l)
                rep (k, n) B[i][j] += (*this)[i][k] * A[k][j];
        swap(*this, B);
        return *this;
    }
    matrix operator+(const matrix& A) const {
        return matrix(*this) += A;
    }
    matrix operator-(const matrix& A) const {
        return matrix(*this) -= A;
    }
    matrix operator*(const matrix& A) const {
        return matrix(*this) *= A;
    }
    const vector<R>& operator[](int i) const {
        return a[i];
    }
    vector<R>& operator[](int i) {
        return a[i];
    }

    vector<R> operator*(const vector<R>& v) const {
        assert(w() == v.size());
        int m = h(), n = w();
        vector<R> res(m);
        rep (i, m)
            rep (j, n) res[i] += (*this)[i][j] * v[j];
        return res;
    }

    int h() const {
        return a.size();
    }
    int w() const {
        return a.empty() ? 0 : a[0].size();
    }

    static matrix identity(int n) {
        matrix I(n);
        // rep (i, n) I[i][i] = R{1};
        rep (i, n) I[i][i] = R{0};
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

const lint INF = 1LL << 62;

// min-plus algebra
struct R {
    lint x;

    R(): x(INF) {}
    R(lint x): x(x) {}
    R& operator+=(const R& m) {
        this->x = min(this->x, m.x);
        return *this;
    }
    R& operator*=(const R& m) {
        this->x += m.x;
        this->x = min(this->x, INF);
        return *this;
    }
    R operator+(const R& m) const {
        return R(*this) += m;
    }
    R operator*(const R& m) const {
        return R(*this) *= m;
    }
};

int main() {
    int n;
    lint k;
    cin >> n >> k;
    matrix<R> A(n);
    rep (i, n)
        rep (j, n) cin >> A[i][j].x;

    auto B = pow(A, k);
    rep (i, n) cout << B[i][i].x << endl;

    return 0;
}
