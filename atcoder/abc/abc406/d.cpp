#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto h = input<int>(), w = input<int>(), n = input<int>();
  vector<int> x(n), y(n);
  rep (i, n) {
    x[i] = input<int>() - 1;
    y[i] = input<int>() - 1;
  }

  map<int, set<int>> X, Y;
  rep (i, n) {
    X[x[i]].emplace(i);
    Y[y[i]].emplace(i);
  }

  auto q = input<int>();
  rep (_, q) {
    auto t = input<int>(), p = input<int>() - 1;
    if (t == 1) {
      output(X[p].size());
      for (int i: X[p]) {
        Y[y[i]].erase(i);
      }
      X.erase(p);
    }
    else {
      output(Y[p].size());
      for (int i: Y[p]) {
        X[x[i]].erase(i);
      }
      Y.erase(p);
    }
  }
}
