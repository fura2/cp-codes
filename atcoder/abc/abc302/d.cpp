#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main() {
	int n, m;
	int64_t d;
	cin >> n >> m >> d;
	vector<int64_t> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(j, m) cin >> b[j];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int64_t ans = -1;
	rep(i, n) {
		int j = upper_bound(b.begin(), b.end(), a[i] + d) - b.begin() - 1;
		if (j >= 0 && b[j] >= a[i] - d) {
			ans = max(ans, a[i] + b[j]);
		}
	}
	cout << ans << endl;

	return 0;
}
