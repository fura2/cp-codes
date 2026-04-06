#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans=INT_MAX;
	rep(i,n){
		int a,p,x; scanf("%d%d%d",&a,&p,&x);
		if(x>a) ans=min(ans,p);
	}
	printf("%d\n",ans<INT_MAX?ans:-1);

	return 0;
}
