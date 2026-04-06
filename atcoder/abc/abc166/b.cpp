#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	bool ok[100]={};
	rep(i,k){
		int d; scanf("%d",&d);
		rep(j,d){
			int a; scanf("%d",&a); a--;
			ok[a]=true;
		}
	}
	printf("%d\n",count(ok,ok+n,false));
	return 0;
}
