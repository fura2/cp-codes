#include "template.hpp"

int main() {
    lint a, b;
    cin >> a >> b;
    cout << lint(pow(a, b) + pow(b, a)) << endl;
    return 0;
}
