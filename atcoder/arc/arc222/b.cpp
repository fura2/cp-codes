#include "template/template.hpp"

#define MULTI_TESTCASE

lint f3(lint a, lint b, lint c) {
  if (!(a >= 1 && b >= 1 && c >= 1)) {
    return 0;
  }
  a--;
  b--;
  c--;
  lint v[] = {a, b, c};
  ranges::sort(v, greater<lint>());
  a = v[0];
  b = v[1];
  c = v[2];
  if (a >= b + c) {
    return b + c;
  }
  else {
    return (a + b + c) / 2;
  }
}

lint f2(lint a, lint b, lint c) {
  if (!(a >= 1 && c >= 1)) {
    return 0;
  }
  a--;
  c--;
  return min(a + b, c);
}

lint f1(lint a, lint b, lint c) {
  if (c == 0 && a == b) {
    return a;
  }
  if (!(b >= 1)) {
    return 0;
  }
  return min(a, b - 1);
}

void testcase() {
  lint a = input();
  lint b = input();
  lint c = input();
  lint ans = f3(a, b, c);
  rep (_, 3) {
    chmax(ans, f1(a, b, c));
    chmax(ans, f2(a, b, c));
    tie(a, b, c) = make_tuple(b, c, a);
  }
  output(ans);
}

int main() {
#ifndef MULTI_TESTCASE
  testcase();
#else
  int t = input();
  rep (i, t) {
#ifdef LOCAL
    std::cerr << std::format("\033[36mCase #{}\033[0m\n", i + 1);
#endif
    testcase();
  }
#endif
  return 0;
}
