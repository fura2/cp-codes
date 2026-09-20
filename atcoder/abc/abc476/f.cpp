#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

vector<lint> f(const vector<lint>& a) {
  int n = a.size();
  vector cum(n + 1, 0LL);
  rep (i, n) cum[i + 1] = cum[i] + a[i];

  vector res(n, 0LL);
  lint up = 0, down = 0;
  rep (i, 1, n) {
    down += cum[n] - cum[i];
  }
  rep (i, n) {
    res[i] = up + down;
    down -= cum[n] - cum[i + 1];
    up += cum[i + 1];
  }
  return res;
}

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto a = input<vector<lint>>(n), b = input<vector<lint>>(n);

  vector B(2 * n, vector(2 * n, 0LL));
  rep (i, n) {
    rep (j, n) {
      int x = i + j, y = i - j + n - 1;
      B[x][y] = a[i] * b[j] % m;
    }
  }

  vector<lint> Br(2 * n), Bc(2 * n);
  rep (x, 2 * n) {
    rep (y, 2 * n) {
      Br[x] += B[x][y];
      Bc[y] += B[x][y];
    }
  }
  auto R = f(Br), C = f(Bc);

  lint ans = 0;
  rep (i, n) {
    rep (j, n) {
      int x = i + j, y = i - j + n - 1;
      ans ^= (R[x] + C[y]) / 2 + i * n + j;
    }
  }
  output(ans);
}
