#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();

  int ans = 0;
  vector<int> a(n);
  rep (_, q) {
    auto i = input<int>() - 1;
    if (a[i] == 0) {
      if (i > 0 && a[i - 1] == 1 && i < n - 1 && a[i + 1] == 1) {
        ans--;
      }
      else if ((i == 0 || a[i - 1] == 0) && (i == n - 1 || a[i + 1] == 0)) {
        ans++;
      }
    }
    else {
      if (i > 0 && a[i - 1] == 1 && i < n - 1 && a[i + 1] == 1) {
        ans++;
      }
      else if ((i == 0 || a[i - 1] == 0) && (i == n - 1 || a[i + 1] == 0)) {
        ans--;
      }
    }
    output(ans);
    a[i] = 1 - a[i];
  }
}
