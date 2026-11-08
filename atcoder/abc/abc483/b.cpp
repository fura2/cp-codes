#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();

  vector<pair<int, int>> a(n);
  rep (i, n) a[i] = {i + 1, 1};

  rep (_, q) {
    int k = input<int>();
    reverse(a.begin(), a.begin() + k);
    rep (i, k) a[i].second *= -1;
  }

  rep (i, n) {
    output(a[i].first * a[i].second);
  }
}
