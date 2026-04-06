#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
	while(1){
		c-=b;
		if(c<=0) return puts("Yes"),0;
		a-=d;
		if(a<=0) return puts("No"),0;
	}
	return 0;
}
