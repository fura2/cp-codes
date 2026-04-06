#include "template.hpp"

int main() {
    string s; cin >> s;
    yesno(set<string>({ "ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD" }).count(s));

    return 0;
}
