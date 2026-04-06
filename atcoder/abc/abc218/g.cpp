// https://atcoder.jp/contests/abc218/editorial/4102

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define show(x) { cout << #x << " = " << x << endl; }

using namespace std;

using graph = vector<vector<int>>;

void add_undirected_edge(graph& G, int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}

const long INF = 1L << 61;

int n;
graph T;
vector<long> a;

// 先手が勝つ (中央値 >= thre にできる) かどうか
// diff: a[u] > thre となる u を通ったら +1, a[u] < thre となる u を通ったら -1
// mn: 使った a[u] のうち thre 以下で最大のもの
// mx: 使った a[u] のうち thre 以上で最小のもの
bool dfs(int u, int p, int turn, int thre, int diff, long mn, long mx) {
    if (a[u] < thre) diff--;
    if (a[u] > thre) diff++;
    if (a[u] <= thre) mn = max(mn, a[u]);
    if (a[u] >= thre) mx = min(mx, a[u]);

    if (T[u].size() == 1 && T[u][0] == p) { // leaf
        if (diff > 0) return true;
        if (diff < 0) return false;
        return mn + mx >= 2 * thre;
    }

    if (turn % 2 == 0) {
        for (int v : T[u]) if (v != p) {
            if (dfs(v, u, 1 - turn, thre, diff, mn, mx)) return true;
        }
        return false;
    }
    else {
        for (int v : T[u]) if (v != p) {
            if (!dfs(v, u, 1 - turn, thre, diff, mn, mx)) return false;
        }
        return true;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    cin >> n;
    a.resize(n);
    rep(u, n) cin >> a[u];
    T = graph(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v; u--; v--;
        add_undirected_edge(T, u, v);
    }

    long lo = 0, hi = 1e9 + 1;
    while (hi - lo > 1) {
        int mi = (lo + hi) / 2;
        if (dfs(0, -1, 0, mi, 0, -INF, INF)) lo = mi;
        else hi = mi;
    }
    cout << lo << endl;

    return 0;
}
