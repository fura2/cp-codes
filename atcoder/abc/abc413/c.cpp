#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto q = input<int>();
  queue<pair<lint, lint>> Q;
  rep (_, q) {
    auto t = input<int>();
    if (t == 1) {
      auto c = input<lint>(), x = input<lint>();
      Q.emplace(x, c);
    }
    else {
      auto k = input<lint>();
      lint ans = 0;
      while (k > 0) {
        auto [x, c] = Q.front();
        if (c <= k) {
          Q.pop();
          ans += c * x;
          k -= c;
        }
        else {
          Q.front().second -= k;
          ans += k * x;
          k = 0;
        }
      }
      output(ans);
    }
  }
}
