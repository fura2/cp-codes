#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,k; scanf("%d%d%d%d",&a,&b,&c,&k);
	if(k<a) printf("%d\n",k);
	else if(k<a+b) printf("%d\n",a);
	else           printf("%d\n",a-(k-a-b));
	return 0;
}
