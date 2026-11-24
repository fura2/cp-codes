#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"

constexpr int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
;

void testcase() {
  int f[128];
  f['R'] = 0;
  f['U'] = 1;
  f['L'] = 2;
  f['D'] = 3;

  auto x1 = input<lint>(), y1 = input<lint>();
  auto x2 = input<lint>(), y2 = input<lint>();
  input<lint>();
  auto m1 = input<int>(), m2 = input<int>();
  vector<pair<int, lint>> p1(m1), p2(m2);
  rep (i, m1) {
    char c = input<char>();
    p1[i] = {f[c], input<lint>()};
  }
  rep (i, m2) {
    char c = input<char>();
    p2[i] = {f[c], input<lint>()};
  }

  auto g = [&](int dir1, int dir2, lint t) {
    int dx1 = dx[dir1], dy1 = dy[dir1];
    int dx2 = dx[dir2], dy2 = dy[dir2];

    lint res = 0;
    if (x1 == x2 && y1 == y2 && dir1 == dir2) {
      res = t;
    }
    else if (dx1 != dx2) {
      if ((x2 - x1) % (dx1 - dx2) == 0) {
        lint s = (x2 - x1) / (dx1 - dx2);
        if (0 < s && s <= t && x1 + s * dx1 == x2 + s * dx2 &&
            y1 + s * dy1 == y2 + s * dy2) {
          res = 1;
        }
      }
    }
    else if (dy1 != dy2) {
      if ((y2 - y1) % (dy1 - dy2) == 0) {
        lint s = (y2 - y1) / (dy1 - dy2);
        if (0 < s && s <= t && x1 + s * dx1 == x2 + s * dx2 &&
            y1 + s * dy1 == y2 + s * dy2) {
          res = 1;
        }
      }
    }
    x1 += t * dx1;
    y1 += t * dy1;
    x2 += t * dx2;
    y2 += t * dy2;
    return res;
  };

  lint ans = 0;
  int i1 = 0, i2 = 0;
  while (i1 < m1) {
    lint t = min(p1[i1].second, p2[i2].second);
    ans += g(p1[i1].first, p2[i2].first, t);
    p1[i1].second -= t;
    p2[i2].second -= t;
    if (p1[i1].second == 0) i1++;
    if (p2[i2].second == 0) i2++;
  }
  output(ans);
}
