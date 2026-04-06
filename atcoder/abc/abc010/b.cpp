#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int ans=0;
	rep(i,n){
		int a; scanf("%d",&a);
		while(a==2 || a==4 || a==5 || a==6 || a==8) a--, ans++;
	}
	printf("%d\n",ans);
	return 0;
}
