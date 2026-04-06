#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	for(int x=1;x<1e5;x++) if((int)(x*0.08)==a && (int)(x*0.1)==b) return printf("%d\n",x),0;
	puts("-1");
	return 0;
}
