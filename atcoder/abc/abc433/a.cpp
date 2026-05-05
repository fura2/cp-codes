#include "template/template.hpp"

int main() {
  int x = input();
  int y = input();
  int z = input();
  rep (t, 10000) {
    if (x + t == z * (y + t)) {
      yes();
      return 0;
    }
  }
  no();
  return 0;
}
