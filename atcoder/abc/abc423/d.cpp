#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto k = input<lint>();
  vector<lint> a(n), b(n), c(n);
  rep (i, n) {
    a[i] = input<lint>();
    b[i] = input<lint>();
    c[i] = input<lint>();
  }

  vector<lint> ans(n);
  queue<int> Q;
  lint cnt = 0;
  priority_queue<tuple<lint, int, int>> Ev;
  rep (i, n) {
    Ev.emplace(-a[i], 1, i);
  }
  while (!Ev.empty()) {
    auto [t, type, i] = Ev.top();
    Ev.pop();
    t *= -1;

    if (type == 1) {  // arrive
      Q.emplace(i);
    }
    else {  // leave
      cnt -= c[i];
    }

    // enter
    while (!Q.empty() && cnt + c[Q.front()] <= k) {
      int j = Q.front();
      Q.pop();
      cnt += c[j];
      Ev.emplace(-(t + b[j]), 0, j);
      ans[j] = t;
    }
  }
  output(ans);
}
