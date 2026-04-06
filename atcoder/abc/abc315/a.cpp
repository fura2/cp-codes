#include "template.hpp"

int main() {
    string s;
    cin >> s;
    for (char c : s)
        if (string("aeiou").find(c) == string::npos)
            cout << c;
    return 0;
}
