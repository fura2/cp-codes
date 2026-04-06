#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	set<pair<int,int>> S;
	rep(i,n){
		int y,x; scanf("%d%d",&y,&x); y--; x--;
		S.emplace(y,x);
	}

	set<pair<int,int>> Cand;
	for(auto p:S) rep(i,3) rep(j,3) {
		int y=p.first+i-1;
		int x=p.second+j-1;
		if(0<y && y<h-1 && 0<x && x<w-1) Cand.emplace(y,x);
	}

	lint ans[10]={};
	for(auto p:Cand){
		int cnt=0;
		rep(i,3) rep(j,3) if(S.count({p.first+i-1,p.second+j-1})>0) cnt++;
		ans[cnt]++;
	}
	ans[0]=1LL*(h-2)*(w-2);
	rep(i,9) ans[0]-=ans[i+1];

	rep(i,10) printf("%lld\n",ans[i]);

	return 0;
}
