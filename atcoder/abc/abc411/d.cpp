#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();

  vector<string> s = {""};
  vector<int> link = {-1};
  vector<int> pos(n + 1);
  rep (_, q) {
    auto t = input<int>(), p = input<int>();
    if (t == 1) {
      pos[p] = pos[0];
    }
    else if (t == 2) {
      auto u = input<string>();
      s.emplace_back(u);
      link.emplace_back(pos[p]);
      pos[p] = s.size() - 1;
    }
    else {
      pos[0] = pos[p];
    }
  }

  vector<int> p;
  for (int i = pos[0]; i != 0; i = link[i]) {
    p.emplace_back(i);
  }
  ranges::reverse(p);
  string ans;
  for (int i: p) ans += s[i];
  output(ans);
}
