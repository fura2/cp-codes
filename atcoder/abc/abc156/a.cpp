#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,r; scanf("%d%d",&n,&r);
	printf("%d\n",n>=10?r:r+100*(10-n));
	return 0;
}
