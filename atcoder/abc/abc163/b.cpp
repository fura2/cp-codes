#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int sum=0;
	rep(i,m){
		int a; scanf("%d",&a);
		sum+=a;
	}
	printf("%d\n",max(n-sum,-1));
	return 0;
}
