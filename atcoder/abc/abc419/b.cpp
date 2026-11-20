#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto q = input<int>();
  multiset<int> S;
  rep (_, q) {
    auto t = input<int>();
    if (t == 1) {
      S.emplace(input<int>());
    }
    else {
      output(*S.begin());
      S.erase(S.begin());
    }
  }
}
