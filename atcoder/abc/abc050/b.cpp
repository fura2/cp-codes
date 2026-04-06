#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int t[100],sum=0;
	rep(i,n) scanf("%d",t+i), sum+=t[i];

	int m; scanf("%d",&m);
	rep(i,m){
		int p,x; scanf("%d%d",&p,&x); p--;
		printf("%d\n",sum-t[p]+x);
	}

	return 0;
}
