#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans=0,mn=n;
	rep(i,n){
		int p; scanf("%d",&p);
		if(p<=mn) ans++, mn=p;
	}
	printf("%d\n",ans);

	return 0;
}
