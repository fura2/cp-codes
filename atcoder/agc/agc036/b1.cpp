// 最初に解いたときのコード

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	a.emplace_back(2e5+1);
	a.emplace_back(2e5+1);
	n+=2;

	vector<int> next(n);
	{
		vector<int> first(2e5+2,-1);
		rep(i,n) if(first[a[i]]==-1) first[a[i]]=i;

		vector<int> nearest(2e5+2,-1);
		for(int i=n-1;i>=0;i--){
			if(nearest[a[i]]==-1){
				next[i]=(first[a[i]]+1)%n;
			}
			else if(nearest[a[i]]==n-1){
				next[i]=0;
			}
			else{
				next[i]=next[nearest[a[i]]+1];
			}
			nearest[a[i]]=i;
		}
	}

	int per;
	for(int p=next[0],t=1;;p=next[p],t++) if(p==0) { per=t; break; }

	int p=0;
	rep(i,(k-1)%per) p=next[p];

	// simulate
	vector<int> ans;
	vector<bool> used(2e5+2);
	for(;p<n;p++){
		if(!used[a[p]]){
			ans.emplace_back(a[p]);
			used[a[p]]=true;
		}
		else{
			while(1){
				int x=ans.back();
				ans.pop_back();
				used[x]=false;
				if(x==a[p]) break;
			}
		}
	}
	rep(i,ans.size()) printf("%d%c",ans[i],i+1<ans.size()?' ':'\n');

	return 0;
}
