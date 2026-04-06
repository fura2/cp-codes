#include "template.hpp"

int main() {
    int n, q; cin >> n >> q;
    map<int, set<int>> f; // card to box
    map<int, multiset<int>> g; // box to card
    rep(q) {
        int type, x; cin >> type >> x;
        if (type == 1) {
            int y; cin >> y;
            f[x].insert(y);
            g[y].insert(x);
        }
        else if (type == 2) {
            for (int a : g[x]) cout << a << " ";
            cout << "\n";
        }
        else if (type == 3) {
            for (int a : f[x]) cout << a << " ";
            cout << "\n";
        }
    }

    return 0;
}
