#include "template.hpp"

int main() {
    int n; cin >> n;
    set<string> S;
    rep(i, n) {
        string s; cin >> s;
        string t = s;
        reverse(all(t));
        S.emplace(min(s, t));
    }
    cout << S.size() << endl;

    return 0;
}
