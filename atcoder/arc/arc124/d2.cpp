#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<vector<int>> cycles(const vector<int>& f){
	int n=f.size();
	vector<vector<int>> res;
	vector<int> color(n,-1);
	rep(u,n) if(color[u]==-1) {
		int v=u;
		do{ color[v]=u; v=f[v]; }while(color[v]==-1);
		if(color[v]==u){
			vector<int> C;
			int w=v;
			do{ C.emplace_back(v); v=f[v]; }while(v!=w);
			res.emplace_back(C);
		}
	}
	return res;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> p(n + m);
	rep(i,n+m) scanf("%d", &p[i]), p[i]--;

	vector<int> R, B, RB;
	for(auto C: cycles(p)){
		if (C.size() == 1) continue;

		bool b1 = false, b2 = false;
		for(int u: C) {
			if(u < n) b1 = true;
			else      b2 = true;
		}
		if(b1 && b2) RB.emplace_back(C.size());
		else if(b1)  R.emplace_back(C.size());
		else         B.emplace_back(C.size());
	}

	if (R.size() < B.size()) swap(R, B);

	int ans = 0;
	for(int k: RB) ans += k - 1;
	for(int k: R)  ans += k + 1;
	for(int k: B)  ans += k - 1;
	printf("%d\n", ans);

	return 0;
}
