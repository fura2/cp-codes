#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(2 * n, 1);

  lint ans = 0;
  map<pair<int, int>, int> pos;
  rep (i, 2 * n - 1) {
    auto p = minmax(a[i], a[i + 1]);
    if (pos.contains(p)) {
      if (pos[p] < i - 1) ans++;
    }
    else
      pos[p] = i;
  }
  rep (i, 2 * n - 3) {
    if (a[i] == a[i + 3] && a[i + 1] == a[i + 2]) ans--;
  }
  output(ans);
}
