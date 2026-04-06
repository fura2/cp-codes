#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%*d%*d%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	map<int,set<int>> X,Y;
	rep(i,n){
		X[y[i]].emplace(x[i]);
		Y[x[i]].emplace(y[i]);
	}

	int cx=0,cy=0;
	for(auto p:X) cx=max<int>(cx,p.second.size());
	for(auto p:Y) cy=max<int>(cy,p.second.size());

	vector<int> Lx,Ly;
	for(auto p:X) if(p.second.size()==cx) Ly.emplace_back(p.first);
	for(auto p:Y) if(p.second.size()==cy) Lx.emplace_back(p.first);

	for(int x0:Lx) for(int y0:Ly) {
		if(X[y0].count(x0)==0 || Y[x0].count(y0)==0){
			printf("%d\n",cx+cy);
			return 0;
		}
	}
	printf("%d\n",cx+cy-1);

	return 0;
}
