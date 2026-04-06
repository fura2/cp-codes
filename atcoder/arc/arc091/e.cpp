#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);

	if(a+b-1>n || 1LL*a*b<n) return puts("-1"),0;

	vector<int> ans(n);
	int idx=0,num=n;
	rep(i,a) ans[idx++]=num+i-a+1;
	num-=a;

	int m=n-(a+b-1);
	for(int i=1;i<b;i++){
		int k=min(a-1,m);
		rep(j,k+1) ans[idx++]=num+j-k;
		num-=k+1;
		m-=k;
	}

	rep(i,n) printf("%d%c",ans[i],i<n-1?' ':'\n');

	return 0;
}
