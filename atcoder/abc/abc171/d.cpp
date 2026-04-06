#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

	lint sum=0;
	map<int,int> f;
	rep(i,n){
		int a; scanf("%d",&a);
		sum+=a;
		++f[a];
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int b,c; scanf("%d%d",&b,&c);
		lint cnt=f[b];
		sum+=cnt*(c-b);
		f[b]=0;
		f[c]+=cnt;
		printf("%lld\n",sum);
	}

	return 0;
}
