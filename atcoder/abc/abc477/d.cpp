#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();

  set<int> S, T;
  rep (x, n) S.emplace(x);

  vector<int> t(q + 1), x(q + 1);
  vector<char> c(q + 1);
  t[0] = 2;
  c[0] = 'a';
  rep (i, 1, q + 1) {
    t[i] = input<int>();
    if (t[i] == 1) {
      x[i] = input<int>() - 1;
      if (S.contains(x[i])) {
        S.erase(x[i]);
        T.emplace(x[i]);
      }
      else if (T.contains(x[i])) {
        T.erase(x[i]);
        S.emplace(x[i]);
      }
    }
    else {
      c[i] = input<char>();
    }
  }

  string ans(n, '?');
  rrep (i, q + 1) {
    if (t[i] == 1) {
      if (S.contains(x[i])) {
        S.erase(x[i]);
        T.emplace(x[i]);
      }
      else if (T.contains(x[i])) {
        T.erase(x[i]);
        S.emplace(x[i]);
      }
    }
    else {
      for (int x: S) ans[x] = c[i];
      S.clear();
    }
  }
  output(ans);
}
