#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto s = input<string>();
  int n = s.size();
  double ans = 0;
  rep (i, n) {
    rep (j, i + 1, n + 1) {
      if (j - i >= 3 && s[i] == 't' && s[j - 1] == 't') {
        int cnt = 0;
        rep (k, i + 1, j - 1)
          if (s[k] == 't') cnt++;
        chmax(ans, 1.0 * cnt / (j - i - 2));
      }
    }
  }
  output(ans);
}
