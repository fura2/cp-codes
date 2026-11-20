#include "template/template.hpp"

#define MULTI_TESTCASE
#include "template/main.hpp"

bool check(vector<lint> a, lint denom, lint numer, lint a0) {
  int n = a.size();
  map<lint, int> h;
  rep (i, n) ++h[a[i]];

  lint x = a0;
  rep (i, n) {
    if (!h.contains(x)) return false;
    if (--h[x] == 0) h.erase(x);
    if (i < n - 1) {
      x *= numer;
      if (x % denom != 0) return false;
      x /= denom;
    }
  }
  return true;
}

void testcase() {
  auto n = input<int>();
  auto a = input<vector<lint>>(n);

  ranges::sort(a, [](lint x, lint y) {
    return abs(x) < abs(y);
  });

  yesno(check(a, a[0], a[1], a[0]) || check(a, a[0], -a[1], a[0]) ||
        check(a, a[0], a[1], -a[0]) || check(a, a[0], -a[1], -a[0]));
}
