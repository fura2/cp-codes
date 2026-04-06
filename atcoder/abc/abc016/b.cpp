#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);

	bool f1=(a+b==c);
	bool f2=(a-b==c);
	if(f1 && f2) puts("?");
	else if(f1)  puts("+");
	else if(f2)  puts("-");
	else         puts("!");

	return 0;
}
