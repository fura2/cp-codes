#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int u,d=0;
	rep(i,n-1){
		printf("? %d %d\n",i+1,n);
		fflush(stdout);
		int tmp; scanf("%d",&tmp);
		if(tmp>d) d=tmp, u=i;
	}
	d=0;
	rep(i,n) if(i!=u) {
		printf("? %d %d\n",u+1,i+1);
		fflush(stdout);
		int tmp; scanf("%d",&tmp);
		if(tmp>d) d=tmp;
	}
	printf("! %d\n",d);
	fflush(stdout);

	return 0;
}
