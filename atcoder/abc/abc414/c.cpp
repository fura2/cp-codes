#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

bool check(lint x, int base) {
  string s;
  while (x > 0) {
    s += '0' + x % base;
    x /= base;
  }
  int n = s.size();
  rep (i, n / 2)
    if (s[i] != s[n - i - 1]) return false;
  return true;
}

void testcase() {
  auto a = input<int>();
  auto n = input<lint>();

  lint ans = 0;
  rep (x, 1000000) {
    string s;
    if (x > 0) s = to_string(x);
    string t = s;
    ranges::reverse(t);
    if (x > 0) {
      lint y = stoll(s + t);
      if (y > n) continue;
      if (check(y, a)) {
        show(y);
        ans += y;
      }
    }
    rep (d, 10) {
      lint y = stoll(s + string(1, '0' + d) + t);
      if (y > n) break;
      if (check(y, a)) {
        show(y);
        ans += y;
      }
    }
  }
  output(ans);
}
