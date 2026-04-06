#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define show(x) { cout << #x << " = " << x << endl; }

using namespace std;

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& e : s) {
        if (!first) os << ", ";
        first = false;
        cout << e;
    }
    os << "}";
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool first = true;
    for (const auto& e : v) {
        if (!first) os << ", ";
        first = false;
        cout << e;
    }
    os << "]";
    return os;
}

const long INF = 1L << 61;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    vector<int> x(n);
    vector<long> y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vector dp(n + 1, vector<long>(2, -INF));
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, 2) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            int j2 = (x[i] == 0 ? max(j - 1, 0) : j + 1);
            if (j2 <= 1) {
                dp[i + 1][j2] = max(dp[i + 1][j2], dp[i][j] + y[i]);
            }
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}
