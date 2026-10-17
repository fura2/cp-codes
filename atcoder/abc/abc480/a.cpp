#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "util/grid.hpp"

void testcase() {
  auto G = input<Grid>(2);
  int ia, ja, id, jd;
  rep (i, 2) {
    rep (j, 2) {
      if (G[i][j] == 'A') ia = i, ja = j;
      if (G[i][j] == 'D') id = i, jd = j;
    }
  }
  yesno(abs(ia - id) + abs(ja - jd) == 1);
}
