#include "template/template.hpp"

int main() {
  int n = input();
  vector<int> a = input(n);
  rep (i, n) {
    bool ok = false;
    rrep (j, i) {
      if (a[j] > a[i]) {
        output(j + 1);
        ok = true;
        break;
      }
    }
    if (!ok) output(-1);
  }
  return 0;
}
