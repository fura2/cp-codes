#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n;
	int k; scanf("%lld%d",&n,&k);
	rep(i,k){
		if(n%200==0) n/=200;
		else         n=n*1000+200;
	}
	printf("%lld\n",n);
	return 0;
}
