#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; scanf("%d%d%d",&n,&a,&b);

	int x=0;
	rep(i,n){
		char s[8];
		int d; scanf("%s%d",s,&d);
		if(s[0]=='E') x+=min(max(d,a),b);
		else          x-=min(max(d,a),b);
	}

	if     (x>0) printf("East %d\n",x);
	else if(x<0) printf("West %d\n",-x);
	else puts("0");

	return 0;
}
