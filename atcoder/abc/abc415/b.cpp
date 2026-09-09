#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();
  vector<int> p;
  rep (i, n) {
    if (s[i] == '#') p.emplace_back(i);
  }
  rep (i, p.size() / 2) output(format("{},{}", p[2 * i] + 1, p[2 * i + 1] + 1));
}
