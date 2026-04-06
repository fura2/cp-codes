#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	int ans=k;
	rep(i,n-1) ans*=k-1;
	printf("%d\n",ans);
	return 0;
}
