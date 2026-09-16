#include "template/template.hpp"

#include <algorithm>

// #define MULTI_TESTCASE
#include "data_structure/binary_trie.hpp"
#include "template/main.hpp"

bool f(const BinaryTrie& T, const string& s, int m) {
  auto p = T.root();
  int cnt = 0;
  for (char c: s) {
    int sub = p->one() ? p->one()->size() : 0;
    if (c == T.zero()) {
      if (cnt + sub > m) return false;
      cnt += sub;
      p = p->zero();
    }
    else {
      if (cnt + sub <= m) return true;
      p = p->one();
    }
  }
  return false;
}

void testcase() {
  auto n = input<int>(), m = input<int>(), k = input<int>();
  auto t = input<string>();
  auto s = input<vector<string>>(n);

  rep (j, k) {
    if (t[j] == 'x') {
      t[j] = 'o';
      rep (i, n) s[i][j] = (s[i][j] == 'o' ? 'x' : 'o');
    }
  }

  BinaryTrie T{'x', 'o'};
  rep (i, n) T.add(s[i]);

  auto q = input<int>();
  rep (_, q) {
    auto x = input<int>() - 1, y = input<int>() - 1;
    T.erase(s[x]);
    s[x][y] = (s[x][y] == 'o' ? 'x' : 'o');
    T.add(s[x]);
    yesno(f(T, s[x], m));
  }
}
