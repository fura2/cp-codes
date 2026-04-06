// 自明に No の場合以外は Yes になる.
// 適当に前処理をして A_1 > A_2 > ... > A_N としておく.
// i (<= N-1) 回目の操作では, M を (固定された) 十分大きい定数として
// (1) A_i ← A_i + x - y
// (2) A_j ← A_j + x  for j != i
// (3) 操作後, A_i は他のどの A_j よりも小さい
// (4) 操作後, A_i - B_i = A_N - B_N (mod M)
// となるように x, y を決める. (これは, y を十分大きく, x を y
// に合わせてうまく取ればできる.) 最後の 1 回の操作で, A_j = B_j (mod M) for all
// j と合わせつつ全体を mod M すればよい.

// x, y の選び方について
//   i = 1 のときを考える.
//   A_1 > A_2 > A_3 > ... > A_N となっている.
//   (1)(2) について
//     y <= A_1 + x < 2*y となってほしい.
//   (2) について
//     A_2 + x < y となってほしい.
//   (3) について
//     A_1 + x - y < A_N + x となってほしい.
//     これは, y > A_1 - A_N が満たされればよい.
//     特に, y > A_1 であればよい.
//   (4) について
//     B_1 - (A_1 + x - y) = B_N - (A_N + x) (mod M) となってほしい.
//     これは, y = (B_N - A_N) - (B_1 - A_1) (mod M) が満たされればよい.
//   以上を満たす選び方として, たとえば
//     y = M + (B_N - A_N) - (B_1 - A_1)
//     x = y - A_2 - 1
//   と取ればよい.
//   一般の i (<= N-1) では
//     y = M * i + (B_N - A_N) - (B_i - A_i)
//     x = y - A_{i+1} - 1
//   と取ればよい.

#include "template.hpp"

int main() {
    int n;
    cin >> n;
    vector<lint> A(n), B(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];

    {
        // sanity check
        map<lint, lint> f;
        rep(i, n) {
            if (f.count(A[i]) > 0) {
                if (f[A[i]] != B[i]) {
                    no();
                    return 0;
                }
            }
            f[A[i]] = B[i];
        }

        // 重複を削除
        A.clear();
        B.clear();
        for (auto [k, v] : f) {
            A.emplace_back(k);
            B.emplace_back(v);
        }
        n = A.size();

        // A が降順になるようにソート
        vector<pair<lint, lint>> P(n);
        rep(i, n) P[i] = {-A[i], B[i]};
        sort(all(P));
        rep(i, n) {
            A[i] = -P[i].first;
            B[i] = P[i].second;
        }
    }

    vector<pair<lint, lint>> ans;
    const lint m = 1e13;
    rep(i, n - 1) {
        lint y = m * (i + 1) + (B[n - 1] - A[n - 1]) - (B[i] - A[i]);
        lint x = y - A[i + 1] - 1;
        assert(0 <= x && x < y);
        rep(j, n) A[j] = (A[j] + x) % y;
        ans.emplace_back(x, y);
    }

    lint x = ((B[n - 1] - A[n - 1]) % m + m) % m;
    lint y = m;
    assert(0 <= x && x < y);
    rep(j, n) A[j] = (A[j] + x) % y;
    ans.emplace_back(x, y);

    yes();
    cout << ans.size() << "\n";
    for (auto [x, y] : ans)
        cout << x << " " << y << "\n";

    return 0;
}
