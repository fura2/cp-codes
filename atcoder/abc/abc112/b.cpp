#include <algorithm>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,T; scanf("%d%d",&n,&T);

	int ans=1001;
	rep(i,n){
		int c,t; scanf("%d%d",&c,&t);
		if(t<=T) ans=min(ans,c);
	}

	if(ans<=1000) printf("%d\n",ans); else puts("TLE");

	return 0;
}
