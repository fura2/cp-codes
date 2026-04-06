#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y,k; scanf("%d%d%d",&x,&y,&k);
	printf("%d\n",k<=y?x+k:x+y-(k-y));
	return 0;
}
