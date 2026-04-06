#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,k,s,t;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);

	int ans;
	if(s+t<k) ans=s*a+t*b;
	else      ans=s*a+t*b-(s+t)*c;
	printf("%d\n",ans);

	return 0;
}
