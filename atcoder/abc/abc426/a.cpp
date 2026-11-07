#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

void testcase() {
  map<string, int> f = {{"Ocelot", 0}, {"Serval", 1}, {"Lynx", 2}};
  auto x = input<string>(), y = input<string>();
  yesno(f[x] >= f[y]);
}
