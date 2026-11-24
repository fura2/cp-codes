#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "typical/inversion_number.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();

  lint ans = LINF;
  rep (_, 2) {
    vector<int> a(2 * n);
    int cnt[2] = {};
    rep (i, 2 * n) {
      int d = s[i] - 'A';
      a[i] = 2 * cnt[d] + d;
      cnt[d]++;
    }
    chmin(ans, inversion_number(a));
    rep (i, 2 * n) s[i] = (s[i] == 'A' ? 'B' : 'A');
  }
  output(ans);
}
