#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,a,b; cin>>n>>a>>b;

	if(a>b) return puts("0"),0;

	if(n==1){
		puts(a==b?"1":"0");
	}
	else{
		printf("%lld\n",(a+(n-1)*b)-((n-1)*a+b)+1);
	}

	return 0;
}
