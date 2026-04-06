#include "template.hpp"

constexpr int INF = 1 << 29;
constexpr int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

struct Point {
    int x, y;
};

struct Crop {
    int id;
    int tp, th; // deadline of planting, harvest time
};

struct Plan {
    Point p;
    Crop c;
    int t; // time to plant
};

int n; // a period of time
int h, w, x0;
vector<vector<bool>> WallH, WallV;

int m; // number of crops
vector<Crop> C;

bool has_wall(int x, int y, int x2, int y2) {
    if (x2 == x + 1) {
        return WallH[x][y];
    }
    if (x2 == x - 1) {
        return WallH[x2][y];
    }
    if (y2 == y + 1) {
        return WallV[x][y];
    }
    if (y2 == y - 1) {
        return WallV[x][y2];
    }
    assert(false);
}

void input() {
    cin >> n >> h >> w >> x0;
    WallH.assign(h - 1, vector(w, false));
    WallV.assign(h, vector(w - 1, false));
    rep (i, h - 1) {
        string s;
        cin >> s;
        rep (j, w) WallH[i][j] = (s[j] == '1');
    }
    rep (i, h) {
        string s;
        cin >> s;
        rep (j, w - 1) WallV[i][j] = (s[j] == '1');
    }
    cin >> m;
    C.resize(m);
    rep (i, m) {
        C[i].id = i;
        cin >> C[i].tp >> C[i].th;
        C[i].tp--;
        C[i].th--;
    }
}

int main() {
    input();

    queue<Point> Q;
    vector D(h, vector(w, -1));
    Q.emplace(x0, 0);
    D[x0][0] = 0;
    while (not Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        rep (k, 4) {
            int x2 = x + dx[k], y2 = y + dy[k];
            if (0 <= x2 and x2 < h and 0 <= y2 and y2 < w and D[x2][y2] == -1) {
                if (not has_wall(x, y, x2, y2)) {
                    Q.emplace(x2, y2);
                    D[x2][y2] = D[x][y] + 1;
                }
            }
        }
    }
    // rep (i, h) {
    //     rep (j, w) {
    //         if (D[i][j] < 10) cout << " ";
    //         cout << D[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int d_max = 0;
    rep (i, h) {
        rep (j, w) {
            chmax(d_max, D[i][j]);
        }
    }
    vector<vector<Point>> d2poss(d_max + 1);
    rep (i, h) {
        rep (j, w) {
            d2poss[D[i][j]].emplace_back(i, j);
        }
    }

    vector<vector<Crop>> t2crops(n);
    rep (i, m) t2crops[C[i].th].emplace_back(C[i]);
    rep (t, n) {
        // descending order by score
        sort(all(t2crops[t]),
             [&](const Crop& c1, const Crop& c2) { return c1.th - c1.tp > c2.th - c2.tp; });
    }

    // edge weights of bipartite graph (left: planting time, right: distance from the start cell)
    vector Value(n, vector<int>(d_max + 1));
    rep (t, n) {
        rep (d, d_max + 1) {
            int sz = min(t2crops[t].size(), d2poss[d].size());
            int value = 0;
            rep (i, sz) value += t2crops[t][i].th - t2crops[t][i].tp + 1;
            Value[t][d] = value;
        }
    }

    // compute order-preserving maximum matching
    vector dp(n + 1, vector(d_max + 2, -INF));
    vector pre(n + 1, vector<pair<int, int>>(d_max + 2, {-1, -1}));
    dp[0][0] = 0;
    rep (t, n + 1) {
        rep (d, d_max + 2) {
            if (t + 1 <= n and chmax(dp[t + 1][d], dp[t][d])) {
                pre[t + 1][d] = {t, d};
            }
            if (d + 1 <= d_max + 1 and chmax(dp[t][d + 1], dp[t][d])) {
                pre[t][d + 1] = {t, d};
            }
            if (t + 1 <= n and d + 1 <= d_max + 1 and chmax(dp[t + 1][d + 1], dp[t][d] + Value[t][d])) {
                pre[t + 1][d + 1] = {t, d};
            }
        }
    }
    // restore matching
    vector<int> match(n, -1);
    {
        int t = n, d = d_max + 1;
        while (not(t == 0 and d == 0)) {
            auto [t_pre, d_pre] = pre[t][d];
            if (t_pre + 1 == t and d_pre + 1 == d) {
                match[t_pre] = d_pre;
            }
            t = t_pre;
            d = d_pre;
        }
    }

    vector<Plan> ans;
    rep (t, n) {
        if (match[t] == -1) continue;
        int d = match[t];
        int sz = min(t2crops[t].size(), d2poss[d].size());
        rep (i, sz) {
            Point p = d2poss[d][i];
            Crop c = t2crops[t][i];
            ans.emplace_back(p, c, t);
        }
    }

    cout << ans.size() << endl;
    rep (i, ssize(ans)) {
        cout << ans[i].c.id + 1 << " " << ans[i].p.x << " " << ans[i].p.y << " " << 1 << endl;
    }

    return 0;
}
