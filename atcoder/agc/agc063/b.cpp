// 明らかに, A_l = 1 である l のみ考えればよい.
// [l, r] が生成可能のとき, 任意の i (l ≦ i ≦ r) に対して [l, i] も生成可能になる.
// 各 l に対して r をどこまで伸ばせるかは, 開始位置 (l) と今どの値まで進んだか (A_i) のペアをスタックで管理することで,
// 全体で O(n) で計算できる.

// A_l = 1 なる 各 l に対して, r をどこまで伸ばせるかの例
// A = [1,2,3,4,1,2,1,2,3,4,5,3,1,2,3,5,6]
//                  |_______|
//              |_____________| |___|
//      |_______________________________|

// A = [1,2,3,1,2,3,4] のような場合には
//      |___| |_____|
// と
//            |___|
//      |___________|
// の二種類の操作列がありうるが, 前者 (スタックを用いたシミュレーションの各時点で伸ばせるだけ伸ばす) の場合だけ考えれば十分.

#include "template.hpp"

int main() {
    int n; cin >> n;
    vector<lint> A(n);
    rep(i, n) cin >> A[i];

    stack<pair<int, int>> S; // (left position, current number)
    vector<int> R(n, -1);
    rep(i, n) {
        if (A[i] == 1) {
            S.emplace(i, 1);
        }
        else if (S.empty()) {
            continue;
        }
        else {
            while (!S.empty() && S.top().second + 1 != A[i]) {
                R[S.top().first] = i;
                S.pop();
            }
            if (!S.empty() && S.top().second + 1 == A[i]) {
                S.top().second++;
            }
        }
    }
    while (!S.empty()) {
        R[S.top().first] = n;
        S.pop();
    }

    lint ans = 0;
    rep(i, n) if (R[i] != -1) ans += R[i] - i;
    cout << ans << endl;

    return 0;
}
