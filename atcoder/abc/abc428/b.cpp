#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();
  auto s = input<string>();

  map<string, int> hist;
  rep (i, n - k + 1) ++hist[s.substr(i, k)];
  int mx = 0;
  for (auto [k, v]: hist) chmax(mx, v);

  output(mx);
  for (auto [k, v]: hist)
    if (v == mx) output(k);
}
