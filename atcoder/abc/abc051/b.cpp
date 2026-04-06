#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k,s; scanf("%d%d",&k,&s);

	int ans=0;
	rep(x,k+1) rep(y,k+1) if(0<=s-x-y && s-x-y<=k) ans++;
	printf("%d\n",ans);

	return 0;
}
