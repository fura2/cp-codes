#include <algorithm>
#include <cmath>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int x[100],y[100],h[100];
	rep(i,n) scanf("%d%d%d",x+i,y+i,h+i);

	rep(cy,101) rep(cx,101) {
		int lo=0,hi=1e9+1000;
		while(lo<hi){
			int mi=(lo+hi+1)/2;
			bool b=true;
			rep(i,n) if(max(mi-abs(x[i]-cx)-abs(y[i]-cy),0)>h[i]) b=false;
			if(b) lo=mi;
			else  hi=mi-1;
		}

		bool ok=true;
		rep(i,n) if(max(lo-abs(x[i]-cx)-abs(y[i]-cy),0)!=h[i]) ok=false;
		if(ok){
			printf("%d %d %d\n",cx,cy,lo);
			break;
		}
	}

	return 0;
}
