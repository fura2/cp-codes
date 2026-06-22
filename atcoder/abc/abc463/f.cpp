#include "template/template.hpp"

// #define MULTI_TESTCASE

class mint {
  static const int MOD = 998244353;
  int x;

 public:
  mint(): x(0) {
  }
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

mint pow(mint m, long long k) {
  mint res = 1;
  for (; k > 0; k >>= 1, m *= m)
    if (k & 1) res *= m;
  return res;
}

mint factorial(int n) {
  static vector<mint> memo = {1};
  if (memo.size() <= n) {
    int k = memo.size();
    memo.resize(n + 1);
    for (; k <= n; k++) memo[k] = memo[k - 1] * k;
  }
  return memo[n];
}

mint factorial_inverse(int n) {
  static vector<mint> memo = {1};
  if (memo.size() <= n) {
    int k = memo.size();
    memo.resize(n + 1);
    memo[n] = inverse(factorial(n));
    for (int i = n; i > k; i--) memo[i - 1] = memo[i] * i;
  }
  return memo[n];
}

mint choose(int n, int k, int type = 0) {
  if (k == 0) return 1;
  if (n < k) return 0;
  if (type == 0) {
    return factorial(n) * factorial_inverse(k) * factorial_inverse(n - k);
  }
  else {
    if (k > n - k) k = n - k;
    mint res = factorial_inverse(k);
    rep (i, k) res *= n - i;
    return res;
  }
}

mint multichoose(int n, int k, int type = 0) {
  return choose(n + k - 1, k, type);
}

mint f1(lint aa, lint ab, lint ac, lint bb, lint bc, lint cc) {
  if (aa == 0) return 0;
  aa--;
  mint res = 0;
  rep (i, ab + ac + 1) {
    res += choose(ab + ac, i) / (i + aa + 1);
  }
  res *= pow(mint(2), aa + bb + bc + cc);
  return res;
}

mint f2(lint aa, lint ab, lint ac, lint bb, lint bc, lint cc) {
  if (ab == 0) return 0;
  ab--;
  mint res = 0;
  rep (i, ab + ac + 1) {
    res += choose(ab + ac, i) / (i + aa + 1);
  }
  res *= pow(mint(2), aa + bb + bc + cc);
  return res;
}

mint f3(lint aa, lint ab, lint ac, lint bb, lint bc, lint cc) {
  if (ac == 0) return 0;
  ac--;
  mint res = 0;
  rep (i, ab + ac + 1) {
    res += choose(ab + ac, i) / (i + aa + 1);
  }
  res *= pow(mint(2), aa + bb + bc + cc);
  return res;
}

mint f4(lint aa, lint ab, lint ac, lint bb, lint bc, lint cc) {
  return 0;
}

mint f5(lint aa, lint ab, lint ac, lint bb, lint bc, lint cc) {
  if (ab == 0) return 0;
  ab--;
  if (aa > 0) return 0;
  mint res = 0;
  rep (i, bc + 1) {
    res += choose(bc, i) / (i + 2 * ab + ac + bb + 2);
  }
  res *= pow(mint(2), bb + cc);
  return res;
}

mint f6(lint aa, lint ab, lint ac, lint bb, lint bc, lint cc) {
  if (ac == 0) return 0;
  ac--;
  if (aa > 0) return 0;
  mint res = 0;
  rep (i, bc + 1) {
    res += choose(bc, i) / (i + 2 * ab + ac + bb + 1);
  }
  res *= pow(mint(2), bb + cc);
  return res;
}

mint f7(lint aa, lint ab, lint ac, lint bb, lint bc, lint cc) {
  return f5(aa, ab, ac, bb, bc, cc);
}

mint f8(lint aa, lint ab, lint ac, lint bb, lint bc, lint cc) {
  if (bb == 0) return 0;
  bb--;
  if (aa > 0) return 0;
  mint res = 0;
  rep (i, bc + 1) {
    res += choose(bc, i) / (i + 2 * ab + ac + bb + 1);
  }
  res *= pow(mint(2), bb + cc);
  return res;
}

mint f9(lint aa, lint ab, lint ac, lint bb, lint bc, lint cc) {
  if (bc == 0) return 0;
  bc--;
  if (aa > 0) return 0;
  mint res = 0;
  rep (i, bc + 1) {
    res += choose(bc, i) / (i + 2 * ab + ac + bb + 1);
  }
  res *= pow(mint(2), bb + cc);
  return res;
}

void testcase() {
  lint n = input();
  vector<lint> a = input(2 * n);

  lint mx = *ranges::max_element(a);

  lint aa = 0, ab = 0, ac = 0, bb = 0, bc = 0, cc = 0;
  rep (i, n) {
    lint x = a[2 * i], y = a[2 * i + 1];
    if (x < y) swap(x, y);
    if (x == mx && y == mx)
      aa++;
    else if (x == mx && y == mx - 1)
      ab++;
    else if (x == mx)
      ac++;
    else if (x == mx - 1 && y == mx - 1)
      bb++;
    else if (x == mx - 1)
      bc++;
    else
      cc++;
  }

  mint res1 = f1(aa, ab, ac, bb, bc, cc);  // AA の A が mx+1 で勝つときの寄与
  mint res2 = f2(aa, ab, ac, bb, bc, cc);  // AB の A が mx+1 で勝つときの寄与
  mint res3 = f3(aa, ab, ac, bb, bc, cc);  // AC の A が mx+1 で勝つときの寄与
  mint res4 = f4(aa, ab, ac, bb, bc, cc);  // AA の A が mx で勝つときの寄与
  mint res5 = f5(aa, ab, ac, bb, bc, cc);  // AB の A が mx で勝つときの寄与
  mint res6 = f6(aa, ab, ac, bb, bc, cc);  // AC の A が mx で勝つときの寄与
  mint res7 = f7(aa, ab, ac, bb, bc, cc);  // AB の B が mx で勝つときの寄与
  mint res8 = f8(aa, ab, ac, bb, bc, cc);  // BB の B が mx で勝つときの寄与
  mint res9 = f9(aa, ab, ac, bb, bc, cc);  // BC の B が mx で勝つときの寄与

  vector<mint> ans(2 * n);
  rep (i, n) {
    lint x = a[2 * i];
    lint y = a[2 * i + 1];
    if (x == mx && y == mx) {
      ans[2 * i] = res1 + res4;
      ans[2 * i + 1] = res1 + res4;
    }
    else if (x == mx && y == mx - 1) {
      ans[2 * i] = res2 + res5;
      ans[2 * i + 1] = res7;
    }
    else if (x == mx - 1 && y == mx) {
      ans[2 * i] = res7;
      ans[2 * i + 1] = res2 + res5;
    }
    else if (x == mx) {
      ans[2 * i] = res3 + res6;
    }
    else if (y == mx) {
      ans[2 * i + 1] = res3 + res6;
    }
    else if (x == mx - 1 && y == mx - 1) {
      ans[2 * i] = res8;
      ans[2 * i + 1] = res8;
    }
    else if (x == mx - 1) {
      ans[2 * i] = res9;
    }
    else if (y == mx - 1) {
      ans[2 * i + 1] = res9;
    }
  }
  mint inv = mint(1) / pow(mint(2), n);
  rep (i, 2 * n) ans[i] *= inv;
  rep (i, 2 * n) cout << ans[i] << " ";
  cout << endl;
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
    std::clog << "\033[36mCase #" << i + 1 << "\033[0m" << std::endl;
    testcase();
  }
#endif
  return 0;
}
