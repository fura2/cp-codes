#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,n; scanf("%d%d",&h,&n);
	rep(i,n){
		int a; scanf("%d",&a);
		h-=a;
	}
	puts(h<=0?"Yes":"No");
	return 0;
}
