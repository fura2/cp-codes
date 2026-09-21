#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n);

  multiset<int> S(a.begin() + 1, a.end() - 1);
  int x = a[0], ans = 2;
  while (2 * x < a[n - 1]) {
    auto it = S.upper_bound(2 * x);
    if (it == S.begin()) {
      output(-1);
      return;
    }
    --it;
    x = *it;
    S.erase(it);
    ans++;
  }
  output(ans);
}
