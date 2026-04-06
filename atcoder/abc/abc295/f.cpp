#include "template.hpp"

string pttn, tar;

lint memo[20][2][2];
// tar 以下の非負整数で pttn を満たすものを数える
lint g(int idx, bool smaller, bool nonzero) {
    lint &res = memo[idx][smaller][nonzero];
    if (res != -1)
        return res;

    if (idx == ssize(tar)) {
        return res = 1;
    }

    res = 0;
    if (smaller) {
        rep(d, 10) {
            if (pttn[idx] == '?' || pttn[idx] == d + '0') {
                if (d == 0 && !nonzero && pttn[idx] == '0')
                    continue;
                res += g(idx + 1, true, nonzero || d != 0);
            }
        }
    } else {
        int tar_d = tar[idx] - '0';
        rep(d, tar_d + 1) {
            if (pttn[idx] == '?' || pttn[idx] == d + '0') {
                if (d == 0 && !nonzero && pttn[idx] == '0')
                    continue;
                res += g(idx + 1, d < tar_d, nonzero || d != 0);
            }
        }
    }
    return res;
}

lint f(string s, lint x) {
    tar = to_string(x);
    if (ssize(s) > ssize(tar))
        return 0;

    lint res = 0;
    rep(i, ssize(tar) - ssize(s) + 1) {
        memset(memo, -1, sizeof memo);
        pttn = string(i, '?') + s + string(ssize(tar) - ssize(s) - i, '?');
        res += g(0, false, false);
    }
    return res;
}

void solve() {
    string s;
    lint l, r;
    cin >> s >> l >> r;

    cout << f(s, r) - f(s, l - 1) << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(t) solve();

    return 0;
}
