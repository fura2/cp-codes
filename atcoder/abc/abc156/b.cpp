#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	int ans=0;
	for(;n>0;n/=k) ans++;
	printf("%d\n",ans);

	return 0;
}
