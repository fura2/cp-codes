#include "template/template.hpp"

void solve() {
  lint x1 = input();
  lint y1 = input();
  lint r1 = input();
  lint x2 = input();
  lint y2 = input();
  lint r2 = input();

  lint d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  if (d2 > (r1 + r2) * (r1 + r2)) {
    no();
    return;
  }
  if (r2 > r1 && d2 < (r2 - r1) * (r2 - r1)) {
    no();
    return;
  }
  if (r1 > r2 && d2 < (r1 - r2) * (r1 - r2)) {
    no();
    return;
  }
  yes();
}

int main() {
  int t = input();
  while (t--) solve();
  return 0;
}
