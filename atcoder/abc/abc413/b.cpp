#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<vector<string>>(n);
  set<string> S;
  rep (i, n)
    rep (j, n)
      if (i != j) S.emplace(s[i] + s[j]);
  output(S.size());
}
