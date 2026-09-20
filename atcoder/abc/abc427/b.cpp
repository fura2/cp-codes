#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

int f(int a) {
  if (a < 10) return a;
  return f(a / 10) + a % 10;
}

void testcase() {
  auto n = input<int>();
  vector<int> a(n + 1);
  a[0] = 1;
  rep (i, 1, n + 1) {
    rep (j, i) a[i] += f(a[j]);
  }
  output(a[n]);
}
