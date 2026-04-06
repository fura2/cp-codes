#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	printf("%02d:%02d:%02d\n",n/3600,n/60%60,n%60);
	return 0;
}
