#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main() {
	int n, m;cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];

	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	do {
		bool ok = true;
		rep(i, n - 1) {
			int cnt = 0;
			rep(j, m) if (s[p[i]][j] != s[p[i + 1]][j]) cnt++;
			if (cnt != 1) ok = false;
		}
		if (ok) {
			cout << "Yes" << endl;
			return 0;
		}
	} while (next_permutation(p.begin(), p.end()));
	cout << "No" << endl;

	return 0;
}
