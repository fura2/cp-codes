#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "string/run_length_encoding.hpp"
#include "template/main.hpp"

void testcase() {
  auto n = input<int>();
  auto s = input<string>();
  int ans = 0;
  for (auto [c, l]: run_length_encoding(s))
    if (c == 'R') chmax(ans, l);
  output(ans);
}
