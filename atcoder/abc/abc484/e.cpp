#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "algebra/collection/add_group.hpp"
#include "data_structure/fenwick_tree.hpp"
#include "template/main.hpp"
#include "util/compression.hpp"

// r 以下を数える
lint solve(vector<lint> a, lint r) {
  int n = a.size();

  Compression<lint> cc{{0}};
  lint cum = 0;
  rep (i, n) {
    cum += a[i];
    cc.add(cum);
  }

  lint ans = 0;
  FenwickTree<AddGroup<int>> F(n + 1);
  cum = 0;
  rep (i, n) {
    F.apply(cc.index(cum), 1);
    cum += a[i];
    ans += F.fold(cc.index(cum - r), n + 1).unwrap();
  }
  return ans;
}

void testcase() {
  auto n = input<int>();
  auto l = input<lint>(), r = input<lint>();
  auto a = input<vector<lint>>(n);
  output(solve(a, r) - solve(a, l - 1));
}
