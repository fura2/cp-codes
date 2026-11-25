#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>(), q = input<int>();

  set<pair<int, int>> S;
  set<int> T;
  rep (_, q) {
    auto t = input<int>(), x = input<int>() - 1;
    if (t == 1) {
      auto y = input<int>() - 1;
      S.emplace(x, y);
    }
    else if (t == 2) {
      T.emplace(x);
    }
    else {
      auto y = input<int>() - 1;
      yesno(S.contains({x, y}) || T.contains(x));
    }
  }
}
