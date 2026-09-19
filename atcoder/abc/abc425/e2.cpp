#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "combinatorics/binomial_table.hpp"
#include "template/main.hpp"

void testcase() {
  auto t = input<int>(), m = input<int>();
  BinomialTable T(5000, 5000, m);
  rep (_, t) {
    auto n = input<int>();
    output(T.multinomial(input<vector<int>>(n)));
  }
}
