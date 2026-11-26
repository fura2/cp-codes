#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/add_group.hpp"
#include "data_structure/fenwick_tree.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto a = input<vector<int>>(n);

  FenwickTree<AddGroup<lint>> F0(n), F1(n), F2(n);
  rep (i, n) {
    F0.set(i, a[i]);
    F1.set(i, 1LL * i * a[i]);
    F2.set(i, 1LL * i * i * a[i]);
  }
  rep (_, q) {
    auto l = input<int>() - 1, r = input<int>();
    // Σ_{l<=j<r} (j-l+1)*(r-j)*A_j
    lint s0 = F0.fold(l, r).unwrap();
    lint s1 = F1.fold(l, r).unwrap();
    lint s2 = F2.fold(l, r).unwrap();
    output(-s2 + (r + l - 1) * s1 - (l - 1LL) * r * s0);
  }
}
