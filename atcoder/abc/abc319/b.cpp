#include "template.hpp"

int main() {
    int n;
    cin >> n;
    string s(n + 1, '-');
    rep (i, n + 1) {
        rep (j, 1, 10) {
            if (n % j == 0 and i % (n / j) == 0) {
                s[i] = '0' + j;
                break;
            }
        }
    }
    cout << s << endl;

    return 0;
}
