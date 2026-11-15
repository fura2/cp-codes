#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n, 1);

  lint ans = 1;
  vector<int> hist(n);
  rep (i, n) {
    if (i > 0 && a[i - 1] != a[i]) {
      ans += i - hist[a[i]];
    }
    hist[a[i]]++;
  }
  output(ans);
}
