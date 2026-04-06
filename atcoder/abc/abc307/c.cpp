#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

void yes() { std::cout << "Yes\n"; }
void no() { std::cout << "No\n"; }
void yesno(bool b) { std::cout << (b ? "Yes" : "No") << "\n"; }

using namespace std;

vector<string> f(vector<string> a) {
    int h = a.size(), w = a[0].size();
    int t = h, b = 0, l = w, r = 0;
    rep(i, h) rep(j, w) if (a[i][j] == '#') {
        t = min(t, i);
        b = max(b, i + 1);
        l = min(l, j);
        r = max(r, j + 1);
    }
    vector<string> res(b - t, string(r - l, '.'));
    rep(i, h) rep(j, w) if (t <= i && i < b && l <= j && j < r) res[i - t][j - l] = a[i][j];
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    int ha, wa; cin >> ha >> wa;
    vector<string> a(ha);
    rep(i, ha) cin >> a[i];
    int hb, wb; cin >> hb >> wb;
    vector<string> b(hb);
    rep(i, hb) cin >> b[i];
    int hx, wx; cin >> hx >> wx;
    vector<string> X(hx);
    rep(i, hx) cin >> X[i];

    a = f(a);
    ha = a.size();
    wa = a[0].size();

    b = f(b);
    hb = b.size();
    wb = b[0].size();

    rep(ia, hx - ha + 1) rep(ja, wx - wa + 1) {
        rep(ib, hx - hb + 1) rep(jb, wx - wb + 1) {
            vector<string> c(hx, string(wx, '.'));
            rep(x, ha) rep(y, wa) if (a[x][y] == '#') c[ia + x][ja + y] = '#';
            rep(x, hb) rep(y, wb) if (b[x][y] == '#') c[ib + x][jb + y] = '#';
            if (c == X) {
                yes();
                return 0;
            }
        }
    }
    no();

    return 0;
}
