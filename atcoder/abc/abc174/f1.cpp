#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<vector<int>> seg;

int query(int l,int r){
	int res=0;
	for(int a=l+seg.size()/2,b=r+seg.size()/2;a<b;a>>=1,b>>=1){
		if(a&1) res+=lower_bound(seg[a].begin(),seg[a].end(),l)-seg[a].begin(), a++;
		if(b&1) b--, res+=lower_bound(seg[b].begin(),seg[b].end(),l)-seg[b].begin();
	}
	return res;
}

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	vector<int> pre(n,-1);
	rep(i,n){
		int x=a[i];
		a[i]=pre[x];
		pre[x]=i;
	}

	int N;
	for(N=1;N<n;N<<=1);
	seg.resize(2*N);
	rep(i,n) seg[N+i].emplace_back(a[i]);
	for(int i=N-1;i>0;i--){
		merge(seg[2*i  ].begin(),seg[2*i  ].end(),
			  seg[2*i+1].begin(),seg[2*i+1].end(),
			  back_inserter(seg[i]));
	}

	rep(_,q){
		int l,r; scanf("%d%d",&l,&r); l--;
		printf("%d\n",query(l,r));
	}

	return 0;
}
