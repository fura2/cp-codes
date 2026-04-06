#include <algorithm>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int b[99];
	rep(i,n-1) scanf("%d",b+i);

	int ans=b[0]+b[n-2];
	rep(i,n-2) ans+=min(b[i],b[i+1]);
	printf("%d\n",ans);

	return 0;
}
