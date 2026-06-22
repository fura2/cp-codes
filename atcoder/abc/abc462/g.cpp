#include "template/template.hpp"

// #define MULTI_TESTCASE

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

vector<mint> roots, iroots;  // roots[i] = 1 の原始 2^i 乗根 in F_p

vector<mint> ntt(vector<mint> p, int dep, const vector<mint>& roots) {
  int n = p.size();
  assert(n == (1 << dep));
  if (n == 1) return p;

  vector<mint> p_even(n / 2), p_odd(n / 2);
  rep (i, n / 2) {
    p_even[i] = p[2 * i];
    p_odd[i] = p[2 * i + 1];
  }
  p_even = ntt(p_even, dep - 1, roots);
  p_odd = ntt(p_odd, dep - 1, roots);

  mint r = 1;
  rep (i, n) {
    p[i] = p_even[i % (n / 2)] + r * p_odd[i % (n / 2)];
    r *= roots[dep];
  }
  return p;
}

vector<mint> convolution(vector<mint> p, vector<mint> q) {
  int n = p.size(), m = q.size();
  int k = n + m - 1;

  int N;
  for (N = 1; N < k; N *= 2);
  int lgN = round(log2(N));
  p.resize(N, 0);
  q.resize(N, 0);

  auto p_hat = ntt(p, lgN, roots);
  auto q_hat = ntt(q, lgN, roots);

  vector<mint> r_hat(N);
  rep (i, N) r_hat[i] = p_hat[i] * q_hat[i];

  auto r = ntt(r_hat, lgN, iroots);
  r.resize(k);
  mint denom = mint(1) / N;
  rep (i, k) r[i] *= denom;
  return r;
}

void testcase() {
  int n = input();
  vector<int> c(n), g(n);
  rep (i, n) {
    c[i] = input();
    c[i]--;
  }
  rep (i, n) {
    g[i] = input();
    g[i]--;
  }

  vector<int> hist(n), deg(n);
  rep (i, n) {
    hist[c[i]]++;
    deg[g[i]]++;
  }

  priority_queue<vector<mint>,
                 vector<vector<mint>>,
                 decltype([](const auto& f, const auto& g) {
                   return f.size() > g.size();
                 })>
      Q;
  rep (i, n) {
    int d = min(hist[i], deg[i]);
    if (d == 0) continue;
    vector<mint> f(d + 1);
    rep (j, d + 1) {
      f[j] = choose(hist[i], j) * choose(deg[i], j) * factorial(j);
    }
    Q.emplace(f);
  }
  Q.push(vector<mint>{1});
  while (Q.size() >= 2) {
    auto f = Q.top();
    Q.pop();
    auto g = Q.top();
    Q.pop();
    auto p = convolution(f, g);
    Q.emplace(p);
  }
  auto p = Q.top();
  p.resize(n + 1);

  mint ans = 0;
  rep (i, n + 1) {
    ans += mint(i % 2 == 0 ? 1 : -1) * factorial(n - i) * p[i];
  }
  ans /= factorial(n);
  output(ans);
}

int main() {
  roots.resize(24);
  iroots.resize(24);
  roots[23] = pow(mint(3), 119);  // 1 の原始 23 乗根 in F_p
  iroots[23] = 1 / roots[23];
  rrep (i, 1, 24) {
    roots[i - 1] = roots[i] * roots[i];
    iroots[i - 1] = iroots[i] * iroots[i];
  }

#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
    std::clog << "\033[32mCase #" << i + 1 << "\033[0m" << std::endl;
    testcase();
  }
#endif
  return 0;
}
