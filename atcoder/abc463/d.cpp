#include "template/template.hpp"

// #define MULTI_TESTCASE

void testcase() {
  int n = input();
  int k = input();
  vector<lint> l(n), r(n);
  rep (i, n) {
    l[i] = input();
    r[i] = input();
  }

  {
    vector<pair<lint, lint>> p(n);
    rep (i, n) p[i] = {r[i], l[i]};
    ranges::sort(p);
    rep (i, n) {
      l[i] = p[i].second;
      r[i] = p[i].first;
    }
  }

  lint lo = 0, hi = 1e10;
  while (hi - lo > 1) {
    lint mi = (lo + hi) / 2;

    int cnt = 0;
    lint mx = -1e10;
    rep (i, n) {
      if (mx + mi <= l[i]) {
        mx = r[i];
        cnt++;
      }
    }
    (cnt >= k ? lo : hi) = mi;
  }
  if (lo == 0) lo = -1;
  output(lo);
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
    std::clog << "\033[36mCase #" << i + 1 << "\033[0m" << std::endl;
    testcase();
  }
#endif
  return 0;
}
