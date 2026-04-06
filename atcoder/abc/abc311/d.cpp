#include "template.hpp"

const int dx[] = { 0, -1, 0, 1 }, dy[] = { 1, 0, -1, 0 };

int main() {
    int h, w; cin >> h >> w;
    vector<string> B(h);
    rep(i, h) cin >> B[i];

    bool vis[200][200] = {};
    queue<pair<int, int>> Q;
    vis[1][1] = true;
    Q.emplace(1, 1);
    while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        rep(k, 4) {
            int x2 = x, y2 = y;
            bool b = true;
            while (1) {
                if (B[x2 + dx[k]][y2 + dy[k]] == '#') break;
                x2 += dx[k];
                y2 += dy[k];
                b = vis[x2][y2];
                vis[x2][y2] = true;
            }
            if (!b) {
                Q.emplace(x2, y2);
            }
        }
    }

    int ans = 0;
    rep(i, h) rep(j, w) if (vis[i][j]) ans++;
    cout << ans << endl;

    return 0;
}
