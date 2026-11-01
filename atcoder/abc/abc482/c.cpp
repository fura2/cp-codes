#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>(), n = input<int>(), q = input<int>();

  vector<int> H, W;
  rep (i, n) {
    auto r = input<int>() - 1, c = input<int>() - 1;
    H.emplace_back(r);
    W.emplace_back(c);
  }
  ranges::sort(H);
  ranges::sort(W);

  rep (_, q) {
    int t = input<int>(), i = input<int>() - 1, j = input<int>();
    auto& A = (t == 1 ? H : W);
    output(ranges::lower_bound(A, j) - ranges::lower_bound(A, i));
  }
}
