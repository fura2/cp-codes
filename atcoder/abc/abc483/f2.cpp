#include "template/template.hpp"

#include <numeric>

// #define MULTI_TESTCASE
#include "template/main.hpp"

int m = 5e5 + 1;
int thresh = sqrt(5e5);

vector<lint> solve1(vector<lint> a, vector<lint> b) {
  int n = a.size();

  vector<vector<lint>> b2as(thresh);
  rep (i, n) b2as[b[i]].emplace_back(a[i]);

  vector<lint> res(m);
  rep (bb, thresh) {
    if (b2as[bb].empty()) continue;

    vector<lint> h(bb);
    for (auto aa: b2as[bb]) h[aa]++;

    lint sum = 0;
    rep (aa, bb) sum += h[aa] * aa;
    int y = bb - 1;  // slightly optimize
    rep (x, m) {
      res[x] += sum;
      sum += b2as[bb].size();
      // sum -= h[bb - 1 - x % bb] * bb;
      sum -= h[y] * bb;
      y--;
      if (y < 0) y += bb;
    }
  }
  return res;
}

vector<lint> solve2(vector<lint> a, vector<lint> b) {
  int n = a.size();

  vector<lint> cum(m);
  cum[0] = reduce(a.begin(), a.end());
  rep (i, n) {
    for (int x = b[i] - a[i]; x < m; x += b[i]) {
      cum[x] -= b[i];
    }
  }
  rep (x, m) {
    cum[x + 1] += cum[x] + n;
  }
  return cum;
}

void testcase() {
  auto n = input<int>();
  vector<lint> a(n), b(n);
  rep (i, n) {
    a[i] = input<lint>();
    b[i] = input<lint>();
  }
  auto q = input<int>();
  auto qs = input<vector<int>>(q);

  vector<lint> a1, b1, a2, b2;
  rep (i, n) {
    (b[i] < thresh ? a1 : a2).emplace_back(a[i]);
    (b[i] < thresh ? b1 : b2).emplace_back(b[i]);
  }
  auto res1 = solve1(a1, b1);
  auto res2 = solve2(a2, b2);

  for (int x: qs) output(res1[x] + res2[x]);
}
