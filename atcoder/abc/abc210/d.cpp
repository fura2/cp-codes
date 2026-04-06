#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int h,w;
	lint c; scanf("%d%d%lld",&h,&w,&c);
	lint a[1000][1000];
	rep(i,h) rep(j,w) scanf("%lld",&a[i][j]);

	lint ans=INF;
	rep(_,2){
		vector mn(h+1,vector(w+1,INF));
		for(int i=h-1;i>=0;i--){
			for(int j=w-1;j>=0;j--){
				ans=min(ans,a[i][j]-c*(i+j+2)+min(mn[i+1][j],mn[i][j+1]));
				mn[i][j]=min({mn[i+1][j],mn[i][j+1],a[i][j]+c*(i+j+2)});
			}
		}
		rep(i,h/2) rep(j,w) swap(a[i][j],a[h-i-1][j]);
	}
	printf("%lld\n",ans);

	return 0;
}
