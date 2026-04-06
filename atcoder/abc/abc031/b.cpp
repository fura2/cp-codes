#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int l,h,n; scanf("%d%d%d",&l,&h,&n);
	rep(i,n){
		int a; scanf("%d",&a);
		printf("%d\n",a>h?-1:max(l-a,0));
	}
	return 0;
}
