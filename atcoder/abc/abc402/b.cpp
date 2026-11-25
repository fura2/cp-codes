#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto q = input<int>();

  queue<int> Q;
  rep (_, q) {
    auto t = input<int>();
    if (t == 1) {
      Q.emplace(input<int>());
    }
    else {
      output(Q.front());
      Q.pop();
    }
  }
}
