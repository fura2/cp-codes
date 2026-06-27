// #define MULTI_TESTCASE
#include "template/template.hpp"

#include "hash/zobrist_hash_set.hpp"

void testcase() {
  auto n = input<int>();
  auto a = input<vector<lint>>(n);
  auto b = input<vector<lint>>(n);

  ZobristHashSet za, zb;
  vector<ulint> ha(n), hb(n);
  rep (i, n) {
    za.insert(a[i]);
    ha[i] = za.hash();
    zb.insert(b[i]);
    hb[i] = zb.hash();
  }

  auto q = input<int>();
  rep (_, q) {
    auto x = input<int>() - 1;
    auto y = input<int>() - 1;
    yesno(ha[x] == hb[y]);
  }
}
