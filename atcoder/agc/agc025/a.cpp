#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int digitsum(int a){
	int res=0;
	for(;a>0;a/=10) res+=a%10;
	return res;
}

int main(){
	int n; scanf("%d",&n);

	int ans=n;
	for(int a=1;a<n;a++) ans=min(ans,digitsum(a)+digitsum(n-a));
	printf("%d\n",ans);

	return 0;
}
