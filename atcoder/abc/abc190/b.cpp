#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);

	rep(i,n){
		int x,y; scanf("%d%d",&x,&y);
		if(x<a && y>b){
			puts("Yes");
			return 0;
		}
	}
	puts("No");

	return 0;
}
