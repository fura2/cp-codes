#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "graph/graph.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), m = input<int>();
  auto G = input<Graph>(n, m, 1);

  bool A[8][8] = {};
  rep (i, m) {
    const auto& e = G.edge(i);
    A[e.from][e.to] = A[e.to][e.from] = true;
  }

  vector<vector<int>> grps;
  vector<int> S;
  auto f = [&](auto&& f, vector<int>& S, int nxt) {
    if (S.size() == n) {
      grps.emplace_back(S);
      return;
    }
    S.emplace_back(-1);
    rep (x, nxt + 1) {
      S.back() = x;
      f(f, S, x == nxt ? nxt + 1 : nxt);
    }
    S.pop_back();
  };
  f(f, S, 0);

  int ans = INF;
  for (auto S: grps) {
    int k = ranges::max(S) + 1;
    vector<vector<int>> ps(k);
    rep (i, n) ps[S[i]].emplace_back(i);

    bool bad = false;
    for (const auto& p: ps)
      if (p.size() <= 2) bad = true;
    if (bad) continue;

    int res = m;  // 仮に全部の辺を消す
    for (auto p: ps) {
      int emax = 0;
      do {
        int e = 0;  // サイクル p 上の辺数
        rep (i, p.size()) {
          int u = p[i], v = p[(i + 1) % p.size()];
          if (A[u][v]) e++;
        }
        chmax(emax, e);
      } while (next_permutation(p.begin() + 1, p.end()));
      res -= emax;             // 消す必要がなかった辺を差し戻す
      res += p.size() - emax;  // 足す必要がある辺を加える
    }
    chmin(ans, res);
  }
  output(ans);
}
