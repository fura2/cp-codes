#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int main(){
	int n,X; scanf("%d%d",&n,&X);
	int ans=0;
	rep(i,n){
		int x; scanf("%d",&x);
		ans=gcd(ans,abs(x-X));
	}
	printf("%d\n",ans);

	return 0;
}
