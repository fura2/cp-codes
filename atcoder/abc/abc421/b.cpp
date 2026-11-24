#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

lint f(int x) {
  string s = to_string(x);
  ranges::reverse(s);
  return stoll(s);
}
void testcase() {
  auto x = input<int>(), y = input<int>();
  vector<lint> a(10);
  a[0] = x;
  a[1] = y;
  rep (i, 2, 10) {
    a[i] = f(a[i - 1] + a[i - 2]);
  }
  output(a[9]);
}
