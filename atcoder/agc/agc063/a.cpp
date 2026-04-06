#include "template.hpp"

int main() {
    int n;
    string s; cin >> n >> s;

    queue<int> A, B;
    rep(i, n + 1) {
        (s[i] == 'A' ? A : B).emplace(i);
    }

    rep(i, n) {
        auto& Q = (i % 2 == 0 ? B : A);
        if (!Q.empty()) {
            Q.pop();
        }
        if (A.empty()) cout << "Bob\n";
        else if (B.empty())  cout << "Alice\n";
        else if (A.front() < B.front()) cout << "Alice\n";
        else cout << "Bob\n";
    }

    return 0;
}
