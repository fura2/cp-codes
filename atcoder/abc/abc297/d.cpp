#include "template.hpp"

int main() {
    lint a, b; cin >> a >> b;

    lint ans = 0;
    while (a != b) {
        if (a < b) swap(a, b);
        if (a % b == 0) {
            ans += a / b - 1;
            break;
        }
        ans += a / b;
        a %= b;
    }
    cout << ans << endl;

    return 0;
}
