#include <algorithm>
#include <cmath>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	int ans=1;
	rep(g,sqrt(m)+1) if(g>0 && m%g==0) {
		if( g <=m/n) ans=max(ans, g );
		if(m/g<=m/n) ans=max(ans,m/g);
	}
	printf("%d\n",ans);

	return 0;
}
