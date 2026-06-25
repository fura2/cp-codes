#include "template/template.hpp"

int main() {
  string s = "HelloWorld";
  int x = input();
  x--;
  output(s.substr(0, x) + s.substr(x + 1));
  return 0;
}
