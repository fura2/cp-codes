#include "template.hpp"

int main() {
    vector<string> W = {"and", "not", "that", "the", "you"};

    int n;
    cin >> n;
    rep(n) {
        string s;
        cin >> s;
        if (count(all(W), s) > 0) {
            yes();
            return 0;
        }
    }
    no();

    return 0;
}
