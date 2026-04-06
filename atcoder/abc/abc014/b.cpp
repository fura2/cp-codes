#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0;
	rep(i,n) if(x>>i&1) ans+=a[i];
	printf("%d\n",ans);

	return 0;
}
