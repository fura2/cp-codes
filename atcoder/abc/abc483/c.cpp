#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  vector<int> a(m), b(m);
  rep (i, m) {
    a[i] = input<int>() - 1;
    b[i] = input<int>() - 1;
  }

  vector<vector<int>> c(n);
  rep (i, m) c[a[i]].emplace_back(i);

  set<pair<int, int>> vote;
  rep (k, n) {
    vote.emplace(-ssize(c[k]), k);
  }
  rep (k, n) {
    for (int i: c[k]) {
      c[b[i]].emplace_back(i);
      vote.emplace(-ssize(c[b[i]]), b[i]);
    }
    vote.erase({-ssize(c[k]), k});

    output(vote.begin()->second + 1);

    for (int i: c[k]) {
      vote.erase({-ssize(c[b[i]]), b[i]});
      c[b[i]].pop_back();
    }
    vote.emplace(-ssize(c[k]), k);
  }
}
