#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>(), t = input<string>();
  int n = s.size();
  rep (i, 1, n) {
    if (isupper(s[i]) && !ranges::contains(t, s[i - 1])) {
      no();
      return;
    }
  }
  yes();
}
