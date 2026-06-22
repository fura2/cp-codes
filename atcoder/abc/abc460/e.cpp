#include "template/template.hpp"

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
  mint& operator/=(const mint& m) { return *this *= inverse(m); }
  mint operator+(const mint& m) const { return mint(*this) += m; }
  mint operator-(const mint& m) const { return mint(*this) -= m; }
  mint operator*(const mint& m) const { return mint(*this) *= m; }
  mint operator/(const mint& m) const { return mint(*this) /= m; }
  mint operator-() const { return -x; }

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
  friend ostream& operator<<(ostream& os, const mint& m) { return os << m.x; }
  int to_int() const { return x; }
};

mint operator+(long long x, const mint& m) { return mint(x) + m; }
mint operator-(long long x, const mint& m) { return mint(x) - m; }
mint operator*(long long x, const mint& m) { return mint(x) * m; }
mint operator/(long long x, const mint& m) { return mint(x) / m; }

// number of x s.t. a * x = 0 (mod m)
lint f(lint n, lint a, lint m) {
  lint g = gcd(a, m);
  return n / (m / g);
}

void solve() {
  lint n = input();
  lint m = input();

  mint ans = 0;
  unsigned long long y_min = 1;
  rep (l, 20) {
    if (y_min > n) break;
    unsigned long long y_max = min<unsigned long long>(10 * y_min - 1, n);
    ans += mint(y_max - y_min + 1) * f(n, (10 * y_min - 1) % m, m);
    y_min *= 10;
  }
  output(ans);
}

int main() {
  int t = input();
  rep (_, t) solve();
  return 0;
}
