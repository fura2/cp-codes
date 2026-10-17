#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  auto n = input<int>(), q = input<int>();
  auto a = input<vector<lint>>(n);

  vector<lint> cum(n + 1);
  rep (i, n) cum[i + 1] = cum[i] + a[i];

  vector<lint> cum2(n + 1);
  rep (i, n) cum2[i + 1] = cum2[i] + cum[i + 1];

  vector<lint> I(n + 1);
  rep (i, n) I[i + 1] = I[i] + i + 1;

  auto query = [&](lint x) {
    int p = upper_bound(I.begin(), I.end(), x) - I.begin() - 1;
    return cum2[p] + cum[x - I[p]];
  };

  rep (_, q) {
    lint l = input<lint>() - 1, r = input<lint>();
    output(query(r) - query(l));
  }
}
