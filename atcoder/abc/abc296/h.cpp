#include "template.hpp"

class union_find {
    int n;
    vector<int> p;
public:
    union_find(int n = 0) { build(n); }
    void build(int n) {
        this->n = n;
        p.assign(n, -1);
    }
    int find(int u) { return p[u] < 0 ? u : p[u] = find(p[u]); }
    void unite(int u, int v) {
        u = find(u); v = find(v);
        if (u != v) {
            if (p[v] < p[u]) swap(u, v);
            p[u] += p[v]; p[v] = u; n--;
        }
    }
    bool is_same(int u, int v) { return find(u) == find(v); }
    int size()const { return n; }
    int size(int u) { return -p[find(u)]; }
};

inline int popcount(unsigned int x) {
    x -= (x >> 1) & 0x55555555;
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    return (((x + (x >> 4)) & 0x0f0f0f0f) * 0x01010101) >> 24;
}

const int INF = 1 << 29;

int main() {
    int h, w; cin >> h >> w;
    vector<string> B;
    rep(i, h) {
        string s; cin >> s;
        if (count(all(s), '#') == 0) {
            h--;
            i--;
            continue;
        }
        B.emplace_back(s);
        break;
    }
    rep(i, B.size(), h) {
        string s; cin >> s;
        B.emplace_back(s);
    }

    // dp[i][T] = (i 行目まで決めて, i 行目の連結性を表す状態が T であるときの, 追加する黒マスの個数の最小値)
    //   T は長さ w の vector で, 値 0 は白マス, 正の値については同じ値のものが既に連結していることを表す
    vector<map<vector<int>, int>> dp(h + 1);
    dp[0][vector<int>(w)] = 0;
    rep(i, h) {
        int Si = 0;
        rep(j, w) if (B[i][j] == '#') Si |= 1 << j;

        for (const auto& [T, v] : dp[i]) {
            rep(S, 1 << w) if ((S & Si) == Si) {
                int cost = popcount(S) - popcount(Si);

                // 一度黒マスが無くなったらそれ以降の行では黒マスを足せない
                if (i > 0 && count(all(T), 0) == w) {
                    if (S != 0) continue;
                }

                // update connectivity
                union_find U(2 * w);
                {
                    vector<int> pre(w, -1);
                    rep(k, w) if (T[k] != 0) {
                        if (pre[T[k]] != -1) {
                            U.unite(k, pre[T[k]]);
                        }
                        pre[T[k]] = k;
                    }
                    rep(k, w) if (bit(S, k)) {
                        U.unite(k, w + k);
                        if (k < w - 1 && bit(S, k + 1)) {
                            U.unite(w + k, w + k + 1);
                        }
                    }
                }

                // check connectivity
                bool ok;
                if (S == 0) {
                    ok = (*max_element(all(T)) <= 1);
                }
                else {
                    ok = true;
                    rep(k, w) if (T[k] != 0) {
                        bool found = false;
                        rep(l, w) {
                            if (bit(S, l) && U.is_same(k, w + l)) {
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (!ok) continue;

                // renumber
                vector<int> T2(w);
                {
                    int m = 1;
                    vector<int> id(2 * w, -1);
                    rep(k, w) if (bit(S, k)) {
                        int val = U.find(w + k);
                        if (id[val] == -1) id[val] = m++;
                        T2[k] = id[val];
                    }
                }

                if (dp[i + 1].count(T2) == 0) dp[i + 1][T2] = INF;
                chmin(dp[i + 1][T2], v + cost);
            }
        }
    }

    int ans = INF;
    for (const auto& [T, v] : dp[h]) {
        if (*max_element(all(T)) <= 1) {
            chmin(ans, v);
        }
    }
    cout << ans << endl;

    return 0;
}
