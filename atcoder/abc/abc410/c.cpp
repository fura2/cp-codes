#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  vector<int> a(n);
  ranges::iota(a, 1);

  int head = 0;
  rep (_, q) {
    auto t = input<int>();
    if (t == 1) {
      auto p = input<int>() - 1, x = input<int>();
      a[(head + p) % n] = x;
    }
    else if (t == 2) {
      auto p = input<int>() - 1;
      output(a[(head + p) % n]);
    }
    else {
      auto k = input<int>();
      head = (head + k) % n;
    }
  }
}
