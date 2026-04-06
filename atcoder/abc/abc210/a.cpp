#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,x,y; cin>>n>>a>>x>>y;

	int ans=0;
	rep(i,n) ans+=(i<a?x:y);
	printf("%d\n",ans);

	return 0;
}
