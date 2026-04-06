#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,d; scanf("%d%d%d",&h,&w,&d);

	int ans=0;
	rep(i,h) rep(j,w) {
		int a; scanf("%d",&a);
		if((i+j)%2==d%2 && i+j<=d) ans=max(ans,a);
	}
	printf("%d\n",ans);

	return 0;
}
