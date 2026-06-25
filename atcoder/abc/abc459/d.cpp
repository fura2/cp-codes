#include "template/template.hpp"

void solve() {
  string s = input();
  int n = s.size();
  int cnt[128] = {};
  rep (i, n) cnt[s[i]]++;

  int mx = *ranges::max_element(cnt);
  if (mx > (n + 1) / 2) {
    no();
    return;
  }

  yes();
  ranges::sort(
      s, [&](char c, char d) { return pair(cnt[c], c) > pair(cnt[d], d); });
  string ans(n, '?');
  int x = 0;
  rep (i, n) {
    ans[x] = s[i];
    x += 2;
    if (x >= n) x = 1;
  }
  output(ans);
}

int main() {
  int t = input();
  rep (_, t) solve();
  return 0;
}
