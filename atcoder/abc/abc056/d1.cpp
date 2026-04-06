// x is need <=> there exists a sum S without x s.t. K-x <= S < K

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	vector<int> a;
	rep(i,n){
		int x; scanf("%d",&x);
		if(x<k) a.emplace_back(x);
	}
	n=a.size();

	static bool dp1[5001][5001]; // dp1[i][w] := ( a[0,i) を使って w が作れるか )
	static bool dp2[5001][5001]; // dp2[i][w] := ( a[n-i,n) を使って w が作れるか )
	dp1[0][0]=dp2[0][0]=true;
	rep(i,n){
		rep(w,k+1){
			dp1[i+1][w]=dp1[i][w];
			dp2[i+1][w]=dp2[i][w];
		}
		for(int w=k;w>=a[  i  ];w--) dp1[i+1][w]|=dp1[i][w-a[  i  ]];
		for(int w=k;w>=a[n-i-1];w--) dp2[i+1][w]|=dp2[i][w-a[n-i-1]];
	}

	static int dp3[5001][5001]; // dp3[i][w] := (a[n-i,n) を使って作れる w 未満の数の種類 )
	rep(i,n+1){
		dp3[i][0]=0;
		rep(w,k) dp3[i][w+1]=dp3[i][w]+dp2[i][w];
	}

	int ans=0;
	rep(i,n){
		bool need=false;
		rep(w,k+1) if(dp1[i][w] && dp3[n-i-1][k-w]-(w<=k-a[i]?dp3[n-i-1][k-w-a[i]]:0)>0) need=true;
		if(!need) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
