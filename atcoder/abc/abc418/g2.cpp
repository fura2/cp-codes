#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void solve(int a, int b, int c, int d, string s) {
  auto op = [&](char x, char y) {
    if (x == '0' && y == '0') return '0' + a;
    if (x == '0' && y == '1') return '0' + b;
    if (x == '1' && y == '0') return '0' + c;
    if (x == '1' && y == '1') return '0' + d;
    assert(false);
  };

  map<string, bool> memo;
  auto dfs = [&](auto&& dfs, string s) {
    if (memo.contains(s)) return memo[s];
    int n = s.size();
    if (n == 0) return memo[s] = false;
    if (n == 1) return memo[s] = (s[0] == '1');
    rep (i, n - 1) {
      string t = s.substr(0, i);
      t += op(s[i], s[i + 1]);
      t += s.substr(i + 2);
      if (dfs(dfs, t)) return memo[s] = true;
    }
    return memo[s] = false;
  };
  auto is_member = [&](string s) { return dfs(dfs, s); };

  // Myhill-Nerode の同値関係を近似的に表現するためのチェック候補となる文字列
  int m = 5;  // max length (大きめに取った)
  vector<string> C;
  rep (l, m + 1) {
    rep (S, 1 << l) {
      string s;
      rep (i, l) s += '0' + bit(S, i);
      C.emplace_back(s);
    }
  }

  auto encode = [&](string s) {
    string res;
    for (const auto& t: C) {
      res += '0' + is_member(s + t);
    }
    return res;
  };

  // build minimum DFA
  // compute states
  map<string, int> f;   // encoded -> state ID
  vector<string> reps;  // state ID -> representative
  queue<string> Q;
  Q.emplace("");
  while (!Q.empty()) {
    auto s = Q.front();
    Q.pop();

    string enc = encode(s);
    if (f.contains(enc)) continue;

    f[enc] = f.size();
    reps.emplace_back(s);
    Q.emplace(s + '0');
    Q.emplace(s + '1');
  }
  // compute transitions
  int n = f.size();
  vector trans(n, vector(2, -1));
  int start = f[encode("")];
  vector<bool> accepted(n);
  rep (u, n) {
    string s = reps[u];
    rep (d, 2) {
      int v = f[encode(s + char('0' + d))];
      trans[u][d] = v;
    }
    accepted[u] = is_member(s);
  }

  // find the longest accepted substring
  int mx = 0;
  {
    vector<int> dp(n, -INF), ndp(n);
    for (char c: s) {
      ranges::fill(ndp, -INF);
      chmax(dp[start], 0);
      rep (u, n) {
        if (dp[u] == -INF) continue;
        int d = c - '0';
        int v = trans[u][d];
        chmax(ndp[v], dp[u] + 1);
      }
      rep (u, n)
        if (accepted[u]) chmax(mx, ndp[u]);
      swap(dp, ndp);
    }
  }
  if (mx == 0) {
    output(vector{-1, 0});
    return;
  }

  // count accepted substrings
  lint cnt = 0;
  {
    vector<lint> dp(n), ndp(n);
    for (char c: s) {
      ranges::fill(ndp, 0);
      dp[start] += 1;
      rep (u, n) {
        int d = c - '0';
        int v = trans[u][d];
        ndp[v] += dp[u];
      }
      rep (u, n)
        if (accepted[u]) cnt += ndp[u];
      swap(dp, ndp);
    }
  }

  output(vector{mx, cnt});
}

void testcase() {
  auto n = input<int>();
  auto s = input<string>();
  rep (a, 2)
    rep (b, 2)
      rep (c, 2)
        rep (d, 2) solve(a, b, c, d, s);
}
