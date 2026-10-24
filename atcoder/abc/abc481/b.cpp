#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();
  auto a = input<vector<int>>(n);

  int ans = 0;
  rep (i, n) {
    if (a[i] == k) ans++;
    if (i < n - 1 && a[i] < k && a[i + 1] > k) ans++;
    if (i < n - 1 && a[i] > k && a[i + 1] < k) ans++;
  }
  output(ans);
}
