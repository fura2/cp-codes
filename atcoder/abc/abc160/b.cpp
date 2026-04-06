#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x; scanf("%d",&x);
	printf("%d\n",x/500*1000+x%500/5*5);
	return 0;
}
