#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector a(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&a[i][j]);

	int mn=INF;
	rep(i,h) rep(j,w) mn=min(mn,a[i][j]);

	int ans=0;
	rep(i,h) rep(j,w) ans+=a[i][j]-mn;
	printf("%d\n",ans);

	return 0;
}
