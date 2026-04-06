#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)

using namespace std;

int match(vector<int> zeros, vector<int> ones, int depth){
	assert(zeros.size()%2 == 1);
	assert(ones.size()%2 == 1);

	rep(i, zeros.size()) zeros[i] &= (1<<depth)-1;
	rep(i, ones.size()) ones[i] &= (1<<depth)-1;
	sort(ones.begin(), ones.end());

	int ans = INT_MAX;
	rep(i, zeros.size()){
		int z = zeros[i];

		// walk on the binary trie of ones
		int res = 0, cur = 0;
		for(int b=depth-1; b>=0; b--){
			cur |= z&(1<<b);
			int idx = lower_bound(ones.begin(), ones.end(), cur) - ones.begin();
			if(idx == ones.size() || cur != (ones[idx] & ~((1<<b)-1))){
				cur ^= 1<<b;
			}
		}
		ans = min(ans, (1<<depth)|(z^cur));
	}
	return ans;
}

int solve(vector<int> a, int depth){
	assert(a.size()%2 == 0);

	if(a.size() == 0 || depth == -1){
		return 0;
	}

	vector<int> zeros, ones;
	rep(i, a.size()){
		if(a[i]>>depth&1) ones.emplace_back(a[i]);
		else              zeros.emplace_back(a[i]);
	}

	if(zeros.size()%2 == 0 && ones.size()%2 == 0){
		return max(solve(zeros, depth-1), solve(ones, depth-1));
	}

	return match(zeros, ones, depth);
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(2*n);
	rep(i, 2*n) scanf("%d", &a[i]);

	printf("%d\n", solve(a, 29));

	return 0;
}
