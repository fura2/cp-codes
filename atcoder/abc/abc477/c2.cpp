#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "string/rolling_hash.hpp"
#include "template/main.hpp"

void testcase() {
  auto q = input<int>();
  auto s = input<string>(), t = input<string>();

  int n = s.size();
  RollingHash Rs(s), Rt(t);
  vector<int> a(n);
  rep (i, n) {
    if (i + t.size() <= n && Rs.hash(i, i + t.size()) == Rt.hash()) a[i] = 1;
  }
  vector<int> cum(n + 1);
  rep (i, n) cum[i + 1] = cum[i] + a[i];

  rep (_, q) {
    auto l = input<int>() - 1, r = input<int>();
    yesno(r - l >= t.size() && cum[r - t.size() + 1] - cum[l] > 0);
  }
}
