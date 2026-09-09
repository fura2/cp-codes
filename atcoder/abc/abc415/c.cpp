#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();
  s = "0" + s;

  vector<bool> vis(1 << n);
  vis[0] = true;
  queue<int> Q;
  Q.emplace(0);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    rep (i, n) {
      if (bit(u, i) == 1) continue;
      int v = u | 1 << i;
      if (!vis[v] && s[v] == '0') {
        vis[v] = true;
        Q.emplace(v);
      }
    }
  }
  yesno(vis[(1 << n) - 1]);
}
