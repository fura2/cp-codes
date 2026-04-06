#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct interval{
	T l,r;
	int id;
	interval():l(T{}),r(T{}){}
	interval(const T& l,const T& r):l(l),r(r){}
	bool operator<(const interval& I)const{ return tie(l,r)<tie(I.l,I.r); }
};

int main(){
	int n; scanf("%d",&n);
	vector<interval<int>> I(n);
	rep(i,n) scanf("%d%d",&I[i].l,&I[i].r), I[i].id=i;

	sort(I.rbegin(),I.rend());

	vector<int> f(n);
	rep(i,n) f[I[i].id]=i;

	// dp[x] := [x,infty) 上での最適解 (選べる区間の最大個数)
	// id[x] := [x,infty) 上での最適解のうち, 最初に選べる区間の番号として最小のもの
	vector<int> dp(1e6+1),id(1e6+1,-1);
	int k=0;
	for(int x=1e6-1;x>=0;x--){
		dp[x]=dp[x+1];
		id[x]=id[x+1];
		while(k<n && I[k].l==x){
			if(dp[x]<dp[I[k].r]+1){
				dp[x]=dp[I[k].r]+1;
				id[x]=I[k].id;
			}
			else if(dp[x]==dp[I[k].r]+1 && id[x]>I[k].id){
				id[x]=I[k].id;
			}
			k++;
		}
	}

	printf("%d\n",dp[0]);
	for(int x=0;dp[x]>0;x=I[f[id[x]]].r) printf("%d%c",id[x]+1,dp[x]>1?' ':'\n');

	return 0;
}
