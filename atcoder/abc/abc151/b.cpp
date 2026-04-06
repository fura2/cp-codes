#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k,m; scanf("%d%d%d",&n,&k,&m);
	int sum=0;
	rep(i,n-1){
		int a; scanf("%d",&a);
		sum+=a;
	}
	if(sum+k<n*m) puts("-1");
	else printf("%d\n",max(n*m-sum,0));

	return 0;
}
