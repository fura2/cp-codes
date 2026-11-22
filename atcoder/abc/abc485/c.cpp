#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "string/run_length_encoding.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n, 1);

  vector<int> ans(n);
  int pos = 0;
  for (auto [c, k]: run_length_encoding(a)) {
    rep (i, k) {
      int x = pos + i;
      if (pos == 0) {
        ans[x] = k - i;
      }
      else if (pos + k == n) {
        ans[x] = i + 1;
      }
      else {
        ans[x] = min(i + 1, k - i);
      }
    }
    pos += k;
  }
  output(ans);
}
