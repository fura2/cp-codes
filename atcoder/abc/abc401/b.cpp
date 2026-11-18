#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();

  int ans = 0;
  bool login = false;
  rep (_, n) {
    auto s = input<string>();
    if (s == "login") login = true;
    if (s == "logout") login = false;
    if (!login && s == "private") ans++;
  }
  output(ans);
}
