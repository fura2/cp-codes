#include "template/template.hpp"

int main() {
  int n = input();
  int m = input();
  vector<int> a(n), b(m);
  rep (i, n) a[i] = input(), a[i] *= 2;
  rep (j, m) b[j] = input();

  ranges::sort(a);
  ranges::sort(b);

  int ans = 0;
  rrep (j, m) {
    if (a.empty()) break;
    if (b[j] <= a.back()) {
      ans++;
      a.pop_back();
    }
  }
  output(ans);

  return 0;
}
