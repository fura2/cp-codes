#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,L; scanf("%d%d",&n,&L);
	vector<int> x(n);
	vector<char> d(n);
	rep(i,n) scanf("%d %c",&x[i],&d[i]), x[i]--;

	lint ans=0;
	int i0,i1;
	for(i0= 0 ;i0< n&&d[i0]=='L';i0++) ans+=x[i0]-i0;
	for(i1=n-1;i1>=0&&d[i1]=='R';i1--) ans+=(L-1)-(n-1-i1)-x[i1];

	vector<tuple<int,int,int>> Pos;
	int pre=i0,mid;
	for(int i=i0;i<=i1;i++){
		if(i+1<=i1 && d[i]=='R' && d[i+1]=='L'){
			mid=i+1;
		}
		else if(i==i1 || (d[i]=='L' && d[i+1]=='R')){
			Pos.emplace_back(pre,mid,i+1);
			pre=i+1;
		}
	}

	for(auto p:Pos){
		int i,j,k; tie(i,j,k)=p;
		for(int t=i;t<j;t++) ans+=x[j-1]-x[t]-(j-1-t);
		for(int t=j;t<k;t++) ans+=x[t]-x[j]-(t-j);
		ans+=max(j-i,k-j)*(x[j]-x[j-1]-1LL);
	}
	printf("%lld\n",ans);

	return 0;
}
