#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,T; scanf("%d%d%d",&n,&m,&T);
	int x=n,t=0;
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		if(a-t>=x){
			puts("No");
			return 0;
		}
		x-=a-t;
		x=min(x+b-a,n);
		t=b;
	}
	puts(T-t<x?"Yes":"No");

	return 0;
}
