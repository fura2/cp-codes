#include "template.hpp"

int main() {
    string s; cin >> s;
    int b1 = s.find('B');
    int b2 = s.rfind('B');
    int r1 = s.find('R');
    int r2 = s.rfind('R');
    int k = s.rfind('K');
    yesno(b1 % 2 != b2 % 2 && r1 < k && k < r2);

    return 0;
}
