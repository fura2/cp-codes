#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();

  int ans = 1;
  rep (i, 1, n) {
    int a = s[i - 1] - '0', b = s[i] - '0';
    ans += (a - b + 10) % 10;
    ans++;
  }
  ans += s[n - 1] - '0';
  output(ans);
}
