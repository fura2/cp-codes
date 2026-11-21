#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto p = input<vector<int>>(n, 1);

  rep (i, n - 1) {
    if (p[i] < p[i + 1]) {
      p.erase(p.begin(), p.begin() + i);
      break;
    }
  }
  n = p.size();

  vector<lint> c;
  rep (i, 1, n - 1) {
    if ((p[i - 1] < p[i] && p[i] > p[i + 1]) ||
        (p[i - 1] > p[i] && p[i] < p[i + 1]))
      c.emplace_back(i);
  }

  lint ans = 0;
  for (int i = 0; i + 1 < c.size(); i += 2) {
    lint l = (i == 0 ? 0 : c[i - 1]);
    lint r = (i + 2 < c.size() ? c[i + 2] : n - 1);
    ans += (c[i] - l) * (r - c[i + 1]);
  }
  output(ans);
}
