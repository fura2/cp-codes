#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int sum[1000002]={};
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		sum[a]++;
		sum[b+1]--;
	}

	rep(i,1000000) sum[i+1]+=sum[i];

	printf("%d\n",*max_element(sum,sum+1000001));

	return 0;
}
