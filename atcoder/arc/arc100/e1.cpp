// O(3^N) solution

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(1<<n);
	rep(S,1<<n) scanf("%d",&a[S]);

	vector<int> dp(1<<n);
	for(int S=1;S<(1<<n);S++){
		dp[S]=dp[S-1];

		int tmp1=0,tmp2=0;
		for(int T=S;T>=0;T=(T-1)&S){
			if(a[T]>tmp1){
				tmp2=tmp1;
				tmp1=a[T];
			}
			else if(a[T]>tmp2){
				tmp2=a[T];
			}
			if(T==0) break;
		}
		dp[S]=max(dp[S],tmp1+tmp2);

		printf("%d\n",dp[S]);
	}

	return 0;
}
