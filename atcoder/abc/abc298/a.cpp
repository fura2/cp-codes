#include "template.hpp"

int main() {
    int n;
    string s; cin >> n >> s;
    yesno(count(all(s), 'o') > 0 && count(all(s), 'x') == 0);

    return 0;
}
