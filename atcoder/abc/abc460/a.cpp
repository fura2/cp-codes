#include "template/template.hpp"

int main() {
  int n = input();
  int m = input();
  int ans = 0;
  while (m != 0) m = n % m, ans++;
  output(ans);
  return 0;
}
