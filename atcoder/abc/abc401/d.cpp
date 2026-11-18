#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), k = input<int>();
  auto s = input<string>();

  rep (i, n) {
    if (s[i] == '?') {
      if (i > 0 && s[i - 1] == 'o')
        s[i] = '.';
      else if (i < n - 1 && s[i + 1] == 'o')
        s[i] = '.';
    }
    else if (s[i] == 'o') {
      k--;
    }
  }

  vector<pair<int, int>> I;
  {
    int cnt = 0;
    rep (i, n + 1) {
      if (i < n && s[i] == '?') {
        cnt++;
      }
      else {
        if (cnt > 0) I.emplace_back(i - cnt, i);
        cnt = 0;
      }
    }
  }

  if (k == 0) {
    for (auto [l, r]: I) {
      rep (i, l, r) {
        assert(s[i] == '?');
        s[i] = '.';
      }
    }
    output(s);
    return;
  }

  int cnt = 0;
  for (auto [l, r]: I) {
    cnt += (r - l + 1) / 2;
  }
  assert(cnt >= k);
  if (cnt == k) {
    for (auto [l, r]: I) {
      if ((r - l) % 2 == 1) {
        rep (i, l, r) {
          assert(s[i] == '?');
          s[i] = ((i - l) % 2 == 0 ? 'o' : '.');
        }
      }
    }
  }
  output(s);
}
