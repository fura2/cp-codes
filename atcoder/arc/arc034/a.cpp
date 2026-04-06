#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	double ans=0;
	rep(i,n){
		int a,b,c,d,e; scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		ans=max(ans,a+b+c+d+e*110/900.0);
	}
	printf("%.9f\n",ans);

	return 0;
}
