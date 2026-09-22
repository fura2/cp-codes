#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/connected_components.hpp"
#include "graph/graph.hpp"
#include "mint/mint.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto s = input<string>();
  auto G = input<Graph>(n, m, 1);

  auto cc = connected_components(G);
  bool dup = false;
  for (const auto& c: cc) {
    string t;
    for (int u: c) t += s[u];
    if (set<int>{from_range, t}.size() != t.size()) dup = true;
  }

  mint ans = 1;
  for (const auto& c: cc) {
    if (c.size() == 1) continue;
    vector<int> b(26);
    for (int u: c) b[s[u] - 'a']++;
    ans *= multinomial(b);
  }
  if (!dup) ans /= 2;
  output(ans);
}
