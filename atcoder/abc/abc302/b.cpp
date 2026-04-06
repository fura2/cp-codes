#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main() {
	int h, w; cin >> h >> w;
	vector<string> B(h);
	rep(i, h) cin >> B[i];

	rep(i, h) rep(j, w) {
		for (int dx = -1;dx < 2;dx++) for (int dy = -1;dy < 2;dy++) if (dx != 0 || dy != 0) {
			string s;
			rep(k, 5) {
				int x = i + k * dx, y = j + k * dy;
				if (0 <= x && x < h && 0 <= y && y < w) s += B[x][y];
			}
			if (s == "snuke") {
				rep(k, 5) {
					int x = i + k * dx, y = j + k * dy;
					cout << x + 1 << " " << y + 1 << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}
