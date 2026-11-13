#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "typical/knapsack_01.hpp"

void testcase() {
  auto n = input<int>(), h = input<int>(), m = input<int>();
  vector<int> a(n), b(n);
  rep (i, n) {
    a[i] = input<int>();
    b[i] = input<int>();
  }

  int lo = 0, hi = n + 1;
  while (hi - lo > 1) {
    int mi = (lo + hi) / 2;
    int bsum = 0;
    vector<int> w(mi), v(mi);
    rep (i, mi) {
      bsum += b[i];
      w[i] = a[i];
      v[i] = b[i];
    }
    (bsum - knapsack_01(w, v, h, KnapsackAlgorithm::WeightDp) <= m ? lo : hi) =
        mi;
  }
  output(lo);
}
