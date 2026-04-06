// 簡潔に書き直したコード

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> next(n);
	{
		vector<vector<int>> Pos(2e5+1);
		rep(i,n) Pos[a[i]].emplace_back(i);
		rep(x,2e5+1) rep(i,Pos[x].size()) next[Pos[x][i]]=Pos[x][(i+1)%Pos[x].size()];
	}

	int per=1;
	{
		int p=0;
		do{
			if(p>=next[p]) per++;
			p=(next[p]+1)%n;
		}while(p!=0);
	}

	if(k%per==0) return 0;

	k=(k-1)%per;

	int p=0;
	while(k>0){
		if(p>=next[p]) k--;
		p=(next[p]+1)%n;
	}

	vector<int> ans;
	while(p<n){
		if(p>=next[p]) ans.emplace_back(a[p]), p++;
		else           p=next[p]+1;
	}
	rep(i,ans.size()) printf("%d%c",ans[i],i+1<ans.size()?' ':'\n');

	return 0;
}
