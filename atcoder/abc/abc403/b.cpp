#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>(), t = input<string>();
  int n = s.size(), m = t.size();
  rep (i, n - m + 1) {
    bool ok = true;
    rep (j, m)
      if (!(s[i + j] == '?' || s[i + j] == t[j])) ok = false;
    if (ok) {
      yes();
      return;
    }
  }
  no();
}
