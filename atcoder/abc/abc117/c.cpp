#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int x[100000];
	rep(i,m) scanf("%d",x+i);

	sort(x,x+m);

	if(n>=m){ puts("0"); return 0; }

	int d[99999];
	rep(i,m) d[i]=x[i+1]-x[i];
	sort(d,d+m-1);

	printf("%d\n",accumulate(d,d+m-n,0));

	return 0;
}
