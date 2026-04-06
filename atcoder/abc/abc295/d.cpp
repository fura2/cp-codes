#include "template.hpp"

int main() {
    string s;
    cin >> s;
    int n = s.size();

    lint ans = 0;
    map<int, lint> cnt;
    ++cnt[0];
    int S = 0;
    rep(i, n) {
        S ^= 1 << (s[i] - '0');
        ans += cnt[S];
        ++cnt[S];
    }
    cout << ans << endl;

    return 0;
}
