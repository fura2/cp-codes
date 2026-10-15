#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto q = input<int>();
  string s;
  int h = 0;
  multiset<int> H = {0};
  rep (_, q) {
    int t = input<int>();
    if (t == 1) {
      char c = input<char>();
      s += c;
      if (c == '(')
        h++;
      else
        h--;
      H.emplace(h);
    }
    else {
      H.erase(H.find(h));
      if (s.back() == '(')
        h--;
      else
        h++;
      s.pop_back();
    }
    yesno(h == 0 && *H.begin() == 0);
  }
}
