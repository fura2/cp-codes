#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define show(x) { std::cerr << #x << " = " << x << endl; }

template<class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e : v) {
        if (!first) os << ", ";
        first = false;
        std::cout << e;
    }
    os << "]";
    return os;
}

using namespace std;

// unsigned int seed = random_device()();
unsigned int seed = 78;
mt19937 rng(seed);

const int n = 30;
const int m = n * (n + 1) / 2;

chrono::system_clock::time_point t_start;

struct Point {
    int x;
    int y;
    bool operator==(const Point& p)const { return x == p.x && y == p.y; }
    bool operator!=(const Point& p)const { return x != p.x || y != p.y; }
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

struct State {
    int a[n][n];
};

std::ostream& operator<<(std::ostream& os, const State& s) {
    int len = 2;
    rep(i, n) rep(j, i + 1) {
        if (s.a[i][j] >= 100) len = 3;
    }
    os << "\n";
    rep(i, n) {
        rep(j, i + 1) {
            string str = to_string(s.a[i][j]);
            rep(_, len - int(str.size())) os << " ";
            os << str << " ";
        }
        if (i < n - 1) os << "\n";
    }
    return os;
}

vector<vector<vector<vector<vector<pair<Point, Point>>>>>> memo_paths;
const vector<pair<Point, Point>>& find_operations(const Point& from, const Point& to) {
    if (from == to) return memo_paths[from.x][from.y][to.x][to.y];

    if (!memo_paths[from.x][from.y][to.x][to.y].empty()) {
        return memo_paths[from.x][from.y][to.x][to.y];
    }

    vector<pair<Point, Point>> ops;
    Point p = from;
    while (p != to) {
        Point q = p;
        if (p.x == to.x) {
            if (p.y < to.y) {
                q.y++;
            }
            else if (p.y > to.y) {
                q.y--;
            }
        }
        else if (p.x < to.x) { // never appeard
            q.x++;
            if (p.y < to.y) {
                q.y++;
            }
        }
        else { // p.x > to.x
            if (p.x > to.x + 1 || (p.x == to.x + 1 && 0 <= p.y - to.y && p.y - to.y <= 1)) {
                q.x--;
                if (p.y > to.y) {
                    q.y--;
                }
            }
            else {
                if (p.y < to.y) {
                    q.y++;
                }
                else if (p.y > to.y) {
                    q.y--;
                }
            }
        }
        ops.emplace_back(p, q);
        p = q;
    }
    return memo_paths[from.x][from.y][to.x][to.y] = ops;
}

vector<int> make_initial_solution(State s, State t) {
    vector<int> res;
    rep(i, n) rep(j, i + 1) {
        vector<Point> cands;
        rep(x, n) rep(y, x + 1) {
            if (pair(i, j) <= pair(x, y)) {
                if (t.a[x][y] == i) cands.emplace_back(Point{ x, y });
            }
        }
        sort(cands.begin(), cands.end(),
            [&](const auto& p, const auto& q) { return make_pair(p.y, p.x) < make_pair(q.y, q.x); }
        );
        auto ops = find_operations(cands[0], Point{ i, j });
        res.emplace_back(s.a[cands[0].x][cands[0].y]);
        for (const auto& [p, q] : ops) {
            swap(s.a[p.x][p.y], s.a[q.x][q.y]);
            swap(t.a[p.x][p.y], t.a[q.x][q.y]);
        }
    }
    return res;
}

vector<pair<Point, Point>> get_operartions(State s, const vector<int>& a) {
    Point f[m];
    rep(x, n) rep(y, x + 1) f[s.a[x][y]] = { x, y };

    vector<pair<Point, Point>> ops;
    int idx = 0;
    rep(x, n) rep(y, x + 1) {
        Point from = f[a[idx++]];
        Point to = { x, y };
        assert(s.a[from.x][from.y] == a[idx - 1]);
        auto tmp = find_operations(from, to);
        ops.insert(ops.end(), all(tmp));
        for (const auto& [p, q] : tmp) {
            swap(f[s.a[p.x][p.y]], f[s.a[q.x][q.y]]);
            swap(s.a[p.x][p.y], s.a[q.x][q.y]);
        }
    }
    return ops;
}

// return (is OK, operation length)
pair<bool, int> get_and_do_operartions(State& s, const vector<int>& a) {
    Point f[m];
    rep(x, n) rep(y, x + 1) f[s.a[x][y]] = { x, y };

    int len = 0;
    int idx = 0;
    rep(x, n) rep(y, x + 1) {
        Point from = f[a[idx++]];
        Point to = { x, y };
        const auto& ops = find_operations(from, to);
        len += ops.size();
        for (const auto& [p, q] : ops) {
            swap(f[s.a[p.x][p.y]], f[s.a[q.x][q.y]]);
            swap(s.a[p.x][p.y], s.a[q.x][q.y]);
        }
        if (x > 0) {
            if ((y <= x - 1 && s.a[x - 1][y] > s.a[x][y]) || (y > 0 && s.a[x - 1][y - 1] > s.a[x][y])) {
                return { false, -1 };
            }
        }
    }
    return { true, len };
}

int main() {
    memo_paths = vector<vector<vector<vector<vector<pair<Point, Point>>>>>>(
        n, vector<vector<vector<vector<pair<Point, Point>>>>>(
            n, vector<vector<vector<pair<Point, Point>>>>(
                n, vector<vector<pair<Point, Point>>>(
                    n, vector<pair<Point, Point>>()
                )
            )
        )
    );

    t_start = chrono::system_clock::now();

    show(seed);
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    State s0;
    rep(i, n) rep(j, i + 1) cin >> s0.a[i][j];

    int f[m]; // 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, ..., n - 1
    {
        int idx = 0;
        rep(x, n) rep(y, x + 1) f[idx++] = x;
        assert(idx == m);
    }
    State t0 = s0;
    rep(i, n) rep(j, i + 1) t0.a[i][j] = f[s0.a[i][j]];

    int g[n][n]; // (0, 0) -> 0, (1, 0) -> 1, (1, 1) -> 2, (2, 0) -> 3, ...
    {
        int idx = 0;
        rep(x, n) rep(y, x + 1) g[x][y] = idx++;
    }

    auto a0 = make_initial_solution(s0, t0);
    int ops_len0 = get_operartions(s0, a0).size();

    auto a_opt = a0;
    int ops_len_opt = ops_len0;
    while (true) {
        auto t_now = chrono::system_clock::now();
        auto dt = chrono::duration_cast<chrono::milliseconds>(t_now - t_start).count();
        if (dt > 1950) break;

        auto& a = a_opt;
        int tar1_x = rng() % (n - 1);
        int tar1_y = rng() % (tar1_x + 1);
        int tar2_x = min<int>(tar1_x + rng() % 3, n - 1);
        int tar2_y = rng() % (tar2_x + 1);
        int idx1 = g[tar1_x][tar1_y];
        int idx2 = g[tar2_x][tar2_y];

        swap(a[idx1], a[idx2]);
        State s = s0;
        auto [b, ops_len] = get_and_do_operartions(s, a);
        if (b && ops_len < ops_len_opt) {
            ops_len_opt = ops_len;
        }
        else {
            swap(a[idx1], a[idx2]); // revert
        }
    }

    auto ans = get_operartions(s0, a_opt);
    cout << ans.size() << endl;
    for (auto [p, q] : ans) cout << p.x << " " << p.y << " " << q.x << " " << q.y << endl;

    return 0;
}
