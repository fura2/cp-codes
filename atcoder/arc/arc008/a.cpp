#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	printf("%d\n",min((n+9)/10*100,n/10*100+n%10*15));
	return 0;
}
