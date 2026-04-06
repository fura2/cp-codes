#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int sum=0,i;
	for(i=1;sum<n;i++){
		sum+=i;
	}
	printf("%d\n",i-1);

	return 0;
}
