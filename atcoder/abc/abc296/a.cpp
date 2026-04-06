#include "template.hpp"

int main() {
    int n;
    string s; cin >> n >> s;
    rep(i, n - 1) if (s[i] == s[i + 1]) {
        no();
        return 0;
    }
    yes();

    return 0;
}
