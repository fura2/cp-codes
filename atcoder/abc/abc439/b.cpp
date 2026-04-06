#include <bits/stdc++.h>

using namespace std;

string f(string n) {
    int x = 0;
    for (char c: n) {
        x += (c - '0') * (c - '0');
    }
    return to_string(x);
}

int main() {
    string n;
    cin >> n;
    for (int i = 0; i < 100000; i++) {
        n = f(n);
    }
    cout << (n == "1" ? "Yes" : "No") << endl;
    return 0;
}
