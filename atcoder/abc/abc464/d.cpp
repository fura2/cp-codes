#define MULTI_TESTCASE
#include "template/template.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();
  auto x = input<vector<lint>>(n);
  auto y = input<vector<lint>>(n - 1);

  vector<lint> dp1(n, -LINF), dp2(n, -LINF);
  if (s[0] == 'S') {
    dp1[0] = 0;
    dp2[0] = -x[0];
  }
  else {
    dp1[0] = -x[0];
    dp2[0] = 0;
  }
  rep (i, n - 1) {
    if (s[i + 1] == 'S') {
      chmax(dp1[i + 1], dp1[i]);
      chmax(dp1[i + 1], dp2[i] + y[i]);
      chmax(dp2[i + 1], dp1[i] - x[i + 1]);
      chmax(dp2[i + 1], dp2[i] - x[i + 1]);
    }
    else {
      chmax(dp1[i + 1], dp1[i] - x[i + 1]);
      chmax(dp1[i + 1], dp2[i] - x[i + 1] + y[i]);
      chmax(dp2[i + 1], dp1[i]);
      chmax(dp2[i + 1], dp2[i]);
    }
  }
  output(max(dp1[n - 1], dp2[n - 1]));
}
