#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,a[100],b[100];
pair<int,int> id[200];

bool vis[100][101],memo[100][101];

bool dfs(int l,int r){
	if(vis[l][r]) return memo[l][r];
	vis[l][r]=true;
	bool& res=memo[l][r];

	if(l==r) return res=true;

	bool all=true;
	rep(i,n){
		if(a[i]!=-1 && b[i]!=-1){
			int cnt=0;
			if(2*l<=a[i] && a[i]<2*r) cnt++;
			if(2*l<=b[i] && b[i]<2*r) cnt++;
			if(cnt==1){
				return res=false;
			}
			if(cnt==2){
				if(b[i]-a[i]!=r-l) all=false;
			}
		}
		else if(a[i]!=-1){
			if(2*l+r-l<=a[i] && a[i]<2*r) all=false;
		}
		else if(b[i]!=-1){
			if(2*l<=b[i] && b[i]<2*l+r-l) all=false;
		}
	}
	rep(i,r-l){
		if(id[2*l+i].first!=-1 && id[2*l+r-l+i].first!=-1 && id[2*l+i].first!=id[2*l+r-l+i].first){
			all=false;
		}
	}
	if(all) return res=true;

	for(int i=l+1;i<r;i++) if(dfs(l,i) && dfs(i,r)) return res=true;
	return res=false;
}

int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]>0) a[i]--;
		if(b[i]>0) b[i]--;
	}

	rep(i,n) if(a[i]!=-1 && b[i]!=-1 && a[i]>=b[i]) {
		puts("No");
		return 0;
	}

	int freq[200]={};
	rep(x,2*n) id[x].first=-1;
	rep(i,n){
		if(a[i]!=-1) freq[a[i]]++, id[a[i]]=make_pair(i,0);
		if(b[i]!=-1) freq[b[i]]++, id[b[i]]=make_pair(i,1);
	}
	rep(x,2*n) if(freq[x]>=2) {
		puts("No");
		return 0;
	}

	puts(dfs(0,n)?"Yes":"No");

	return 0;
}
