// #define MULTI_TESTCASE
#include "template/template.hpp"

void testcase() {
  auto n = input<int>();
  auto m = input<int>();

  map<int, int> H;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
      Q;
  rep (i, n) {
    auto a = input<int>();
    auto d = input<int>() - 1;
    auto b = input<int>();
    ++H[a];
    if (a != b) Q.emplace(d, a, b);
  }

  vector<int> ans(m);
  rep (j, m) {
    while (!Q.empty() && get<0>(Q.top()) == j) {
      auto [d, a, b] = Q.top();
      Q.pop();
      ++H[b];
      --H[a];
      if (H[a] == 0) H.erase(a);
    }
    ans[j] = H.size();
  }
  output(ans);
}
