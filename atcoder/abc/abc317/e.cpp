#include "template.hpp"

constexpr int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> B(h);
    rep (i, h) cin >> B[i];

    int sx, sy, gx, gy;
    rep (i, h) {
        rep (j, w) {
            if (B[i][j] == 'S') {
                sx = i;
                sy = j;
                B[i][j] = '.';
            }
            else if (B[i][j] == 'G') {
                gx = i;
                gy = j;
                B[i][j] = '.';
            }
        }
    }

    rep (i, h) {
        rep (j, w) {
            int k = string(">^<v").find(B[i][j]);
            if (k != string::npos) {
                int x = i + dx[k], y = j + dy[k];
                while (0 <= x and x < h and 0 <= y and y < w and (B[x][y] == '.' or B[x][y] == 'x')) {
                    B[x][y] = 'x';
                    x += dx[k];
                    y += dy[k];
                }
            }
        }
    }

    vector D(h, vector(w, -1));
    queue<pair<int, int>> Q;
    D[sx][sy] = 0;
    Q.emplace(sx, sy);
    while (not Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        rep (k, 4) {
            int x2 = x + dx[k], y2 = y + dy[k];
            if (0 <= x2 and x2 < h and 0 <= y2 and y2 < w and B[x2][y2] == '.' and D[x2][y2] == -1) {
                D[x2][y2] = D[x][y] + 1;
                Q.emplace(x2, y2);
            }
        }
    }
    cout << D[gx][gy] << endl;

    return 0;
}
