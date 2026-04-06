#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint dp_min[2][2001]; // dp[t][i] = t 日目までに i 勝するための最小勝利回数
	lint dp_max[2][2001]; // dp[t][i] = t 日目までに i 勝するための最大勝利回数
	lint sum=0;
	int curr=0,next=1;
	rep(i,n+1){
		dp_min[curr][i]=(i==0?0:INF);
		dp_max[curr][i]=(i==0?0:-INF);
	}
	rep(t,n){
		rep(i,n+1){
			dp_min[next][i]=INF;
			dp_max[next][i]=-INF;
		}

		// 勝利回数を増やさない
		if(t==0){
			dp_min[next][0]=0;
			dp_max[next][0]=0;
		}
		else{
			rep(i,n+1){
				dp_min[next][i]=dp_min[curr][i];
				if(dp_max[curr][i]>-INF){
					lint tmp=dp_max[curr][i]*(sum+a[t])/sum;
					dp_max[next][i]=min(tmp,dp_max[curr][i]+a[t]);
				}
			}
		}

		// 勝利回数を増やす
		if(t==0){
			dp_min[next][1]=1;
			dp_max[next][1]=a[0];
		}
		else{
			rep(i,n) if(dp_min[curr][i]<INF) {
				lint tmp=dp_min[curr][i]*(sum+a[t])/sum+1;
				if(tmp-dp_min[curr][i]<=a[t]){
					dp_min[next][i+1]=min(dp_min[next][i+1],tmp);
					dp_max[next][i+1]=max(dp_max[next][i+1],dp_max[curr][i]+a[t]-(dp_max[curr][i]==sum?1:0));
				}
			}
		}

		sum+=a[t];
		swap(curr,next);
	}

	int ans=0;
	rep(i,n+1) if(dp_min[curr][i]<=k && k<=dp_max[curr][i]) ans=i;
	printf("%d\n",ans);

	return 0;
}
