#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto p = input<vector<int>>(n, 1);
  while (true) {
    bool ok = true;
    rep (i, n - 1)
      if (p[i] > p[i + 1]) ok = false;
    if (ok) break;
    cout << "shuffle" << endl;
    p = input<vector<int>>(n, 1);
  }
  cout << "ok" << endl;
}
