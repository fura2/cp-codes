#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int tri[1000000]={0,0,1};
	for(int i=3;i<n;i++) tri[i]=(tri[i-1]+tri[i-2]+tri[i-3])%10007;
	printf("%d\n",tri[n-1]);

	return 0;
}
