#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto B = input<vector<string>>(5);

  int ans = 5;
  rep (i, 5) {
    int cnt = 0;
    rep (j, 5)
      if (B[i][j] == '.') cnt++;
    chmin(ans, cnt);
  }
  rep (j, 5) {
    int cnt = 0;
    rep (i, 5)
      if (B[i][j] == '.') cnt++;
    chmin(ans, cnt);
  }
  {
    int cnt = 0;
    rep (i, 5)
      if (B[i][i] == '.') cnt++;
    chmin(ans, cnt);
  }
  {
    int cnt = 0;
    rep (i, 5)
      if (B[i][4 - i] == '.') cnt++;
    chmin(ans, cnt);
  }
  output(ans);
}
