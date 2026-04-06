// 解説を見ながら
// https://atcoder.jp/contests/abc313/editorial/6902

#include "template.hpp"

const double INF = 1e60;

int main() {
    int n, m;
    cin >> n >> m;
    vector<double> A(n), B(n);
    rep(u, n) cin >> A[u] >> B[u];

    vector Adj(n, vector(n, false));
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        Adj[u][v] = Adj[v][u] = true;
    }

    // 各頂点 u に対して
    // - 隣接する辺のうち一つでも選んでいたなら, u の答えへの寄与は (A[u] + B[u])/2
    // - 隣接する辺を一つも選んでいなれば, u の答えへの寄与は A[u]
    rep(u, n) {
        if (Adj[u][u]) {
            if (A[u] < B[u])
                swap(A[u], B[u]);
            Adj[u][u] = false;
        }
        B[u] = (A[u] + B[u]) / 2;
    }

    // Pos[i] = u: 頂点 u に接続する辺が選ばれていたら +B[u] 点
    // Neg[i] = u: 頂点 u に接続する辺が選ばれていたら -B[u] 点
    vector<int> Pos, Neg;
    rep(u, n) {
        if (A[u] <= B[u]) {
            Pos.emplace_back(u);
            B[u] = B[u] - A[u];
        } else {
            Neg.emplace_back(u);
            B[u] = A[u] - B[u];
        }
    }
    int n_pos = Pos.size(), n_neg = Neg.size();

    vector<lint> neg2poss(n_neg); // neg2poss[i] = (Neg[i] に隣接する Pos の頂点たち)
    rep(i, n_pos) {
        int u = Pos[i];
        rep(j, n_neg) {
            int v = Neg[j];
            if (Adj[u][v]) {
                neg2poss[j] |= 1LL << i;
            }
        }
    }

    lint pos_good_set = 0; // 必ず使う Pos の頂点たち
    rep(i, n_pos) {
        int u = Pos[i];
        rep(j, n_pos) {
            int v = Pos[j];
            if (Adj[u][v]) {
                pos_good_set |= 1LL << i;
                pos_good_set |= 1LL << j;
            }
        }
    }

    double ans = accumulate(all(A), 0.0);
    if (n_pos >= n_neg) {
        double res = 0;
        rep(S, 1 << n_neg) { // 使う Neg の頂点集合が S に一致するとき
            lint pos_set = pos_good_set;
            rep(i, n_neg) if (bit(S, i)) {
                pos_set |= neg2poss[i];
            }

            double val = 0;
            rep(i, n_pos) if (bit(pos_set, i)) val += B[Pos[i]];
            rep(i, n_neg) if (bit(S, i)) val -= B[Neg[i]];
            chmax(res, val);
        }
        ans += res;
    } else {
        // dp[i][S] = (Neg の頂点を先頭 i 個まで見て, 使う Pos の頂点集合が S であるときの, Neg からの寄与の最大値)
        vector dp(n_neg + 1, vector(1 << n_pos, -INF));
        dp[0][pos_good_set] = 0;
        rep(i, n_neg) rep(S, 1 << n_pos) {
            chmax(dp[i + 1][S], dp[i][S]);                           // 頂点 Neg[i] を使わない
            chmax(dp[i + 1][S | neg2poss[i]], dp[i][S] - B[Neg[i]]); // 頂点 Neg[i] を使う
        }

        double res = 0;
        rep(S, 1 << n_pos) {
            double val = dp[n_neg][S];
            rep(i, n_pos) if (bit(S, i)) val += B[Pos[i]];
            chmax(res, val);
        }
        ans += res;
    }
    cout << ans << endl;

    return 0;
}
