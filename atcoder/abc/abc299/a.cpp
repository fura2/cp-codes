#include "template.hpp"

int main() {
    int n;
    string s; cin >> n >> s;

    int i = s.find('*');
    string t = s.substr(0, i);
    cout << (count(all(t), '|') == 1 ? "in" : "out") << endl;

    return 0;
}
