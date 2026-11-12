#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/second_max_monoid.hpp"
#include "set_operation/zeta_transform.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(1 << n);

  vector<SecondMaxMonoid<int>> f(1 << n);
  rep (S, 1 << n) f[S] = pair{a[S], -INF};
  subset_zeta_transform_inplace(f);

  int ans = -INF;
  rep (S, 1, 1 << n) {
    chmax(ans, f[S].unwrap().first + f[S].unwrap().second);
    output(ans);
  }
}
