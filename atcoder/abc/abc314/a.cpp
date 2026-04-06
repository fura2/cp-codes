#include "template.hpp"

int main() {
    string s = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    int n;
    cin >> n;
    cout << s.substr(0, n + 2) << endl;

    return 0;
}
