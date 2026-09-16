#include "template/template.hpp"

#include <algorithm>

// #define MULTI_TESTCASE
#include "template/main.hpp"

class BinaryTrieNode {
 public:
  BinaryTrieNode(): sz{0}, l{nullptr}, r{nullptr} {
  }

  int size() const {
    return sz;
  }
  BinaryTrieNode* zero() const {
    return l;
  }
  BinaryTrieNode* one() const {
    return r;
  }

 private:
  int sz;
  BinaryTrieNode* l;
  BinaryTrieNode* r;

  friend class BinaryTrie;
};

class BinaryTrie {
 public:
  BinaryTrie(char zero = '0', char one = '1')
      : c0{zero}, c1{one}, r{new BinaryTrieNode{}} {
  }

  const BinaryTrieNode* root() const {
    return r;
  }
  char zero() const {
    return c0;
  }
  char one() const {
    return c1;
  }

  void add(const string& s) {
    BinaryTrieNode* p = r;
    p->sz++;
    for (const auto& c: s) {
      if (c == c0) {
        if (!p->l) p->l = new BinaryTrieNode{};
        p = p->l;
      }
      else if (c == c1) {
        if (!p->r) p->r = new BinaryTrieNode{};
        p = p->r;
      }
      else {
        assert(false);
      }
      p->sz++;
    }
  }

  void erase(const string& s) {
    BinaryTrieNode* p = r;
    p->sz--;
    for (const auto& c: s) {
      if (c == c0)
        p = p->l;
      else if (c == c1)
        p = p->r;
      else
        assert(false);
      p->sz--;
    }
  }

 private:
  char c0, c1;
  BinaryTrieNode* r;
};

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
