#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  int l = n - 1;
  rep (i, n - 1) {
    if (s[i] > s[i + 1]) {
      l = i;
      break;
    }
  }
  int r = n - 1;
  rep (i, l + 1, n - 1) {
    if (s[i + 1] > s[l]) {
      r = i;
      break;
    }
  }
  r++;
  rotate(s.begin() + l, s.begin() + l + 1, s.begin() + r);
  output(s);
}
