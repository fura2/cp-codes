#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

bool check(vector<int> a, vector<int> b) {
  int n = a.size();

  int i;
  for (i = 0; i < n; i++) {
    if (a[i] != b[i]) break;
  }
  if (i == n) return true;

  int j;
  for (j = i; j < n - 1; j++) {
    if (a[j + 1] != b[j]) break;
  }
  if (j == n - 1) return a[i] == b[n - 1];
  if (a[i] != b[j]) return false;

  rep (k, j + 1, n) {
    if (a[k] != b[k]) return false;
  }
  return true;
}

void testcase() {
  auto n = input<int>();
  auto a = input<vector<int>>(n), b = input<vector<int>>(n);

  if (check(a, b)) {
    yes();
    return;
  }
  ranges::reverse(a);
  ranges::reverse(b);
  if (check(a, b)) {
    yes();
    return;
  }
  no();
}
