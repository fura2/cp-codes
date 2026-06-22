#include "template/template.hpp"

constexpr int dx[] = {0, -1, -1, -1, 0, 1, 1, 1},
              dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  int h = input();
  int w = input();
  vector<string> B(h);
  rep (i, h) cin >> B[i];

  {
    vector<string> B2(h, string(w, '.'));
    rep (x, h)
      rep (y, w)
        if (B[x][y] == '#') {
          rep (k, 8) {
            int x2 = x + dx[k], y2 = y + dy[k];
            if (0 <= x2 && x2 < h && 0 <= y2 && y2 < w && B[x2][y2] == '.') {
              B2[x2][y2] = '#';
            }
          }
        }
    B = B2;
  }

  int cnt = 0;
  rep (i, h)
    rep (j, w)
      if (B[i][j] == '#') cnt++;
  if (cnt == 0) {
    rep (i, h) cout << B[i] << endl;
    return 0;
  }

  queue<pair<int, int>> Q;
  vector d(h, vector(w, INF));
  rep (i, h)
    rep (j, w)
      if (B[i][j] == '#') d[i][j] = 0, Q.emplace(i, j);
  while (!Q.empty()) {
    auto [x, y] = Q.front();
    Q.pop();
    rep (k, 8) {
      int x2 = x + dx[k], y2 = y + dy[k];
      if (0 <= x2 && x2 < h && 0 <= y2 && y2 < w && d[x2][y2] == INF) {
        d[x2][y2] = d[x][y] + 1;
        Q.emplace(x2, y2);
      }
    }
  }

  rep (i, h)
    rep (j, w) {
      B[i][j] = (d[i][j] % 2 == 0 ? '.' : '#');
    }
  rep (i, h) cout << B[i] << endl;

  return 0;
}
