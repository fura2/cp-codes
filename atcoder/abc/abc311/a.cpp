#include "template.hpp"

int main() {
    int n;
    string s; cin >> n >> s;
    rep(i, n) {
        string t = s.substr(0, i + 1);
        if (set(all(t)).size() == 3) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}
