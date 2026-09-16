#include "template/template.hpp"

#define MULTI_TESTCASE
#include "number_theory/eratosthenes_sieve.hpp"
#include "template/main.hpp"

vector<int> P;

lint n, d;
vector<int> dexp;  // dexp[i] = (d が P[i] で何回割れるか)
lint sig_max, ans;

bool f(lint a, lint b, lint m) {
  return __int128_t(a) * b % m == 0;
}

// fre: すでに d の倍数が作れなくなったかどうか
void dfs(lint a, lint sig, bool fre, vector<int>& E) {
  int k = E.size();
  if (k >= 1 && E[k - 1] == 0 && (fre || dexp[k - 1] == 0)) {
    return;
  }
  if (k >= 2 && E[k - 2] < E[k - 1] && (fre || dexp[k - 2] == 0)) {
    return;
  }

  if (k >= 2 && E[k - 2] < dexp[k - 2]) fre = true;

  if (chmax(sig_max, sig)) ans = a;

  E.emplace_back(0);
  lint q = 1;
  for (int e = 0;; e++) {
    if (a > n / q) break;
    if (!f(a, q, d)) {
      E.back() = e;
      dfs(a * q, sig * (1 + e), fre, E);
      E.back() = 0;
    }
    q *= P[k];
  }
  E.pop_back();
}

void testcase() {
  P = EratosthenesSieve{100}.primes();

  n = input<lint>();
  d = input<lint>();

  {
    dexp.clear();
    lint tmp = d;
    for (int p: P) {
      int e = 0;
      while (tmp % p == 0) {
        tmp /= p;
        e++;
      }
      dexp.emplace_back(e);
    }
  }

  vector<int> E;
  sig_max = 1;
  ans = 1;
  dfs(1, 1, false, E);
  output(ans);
}
