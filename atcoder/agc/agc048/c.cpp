#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

lint solve(vector<int> a,vector<int> b){
	int n=a.size();

	vector dp(2,vector(n+1,INF));
	rep(t,2){
		map<int,int> f;

		dp[t][n]=0;
		for(int i=n-1;i>=0;i--){
			if(a[i]==b[i]){
				dp[t][i]=dp[t][i+1];
			}
			else if(a[i]<b[i]){
				if(f.count(b[i]-i)==0) continue;
				int j=f[b[i]-i];
				if(b[i+1]==a[j]-(j-i-1)){
					dp[t][i]=dp[t][i+1]+1;
				}
				else{
					dp[t][i]=dp[t][i+1]+(j-i);
				}
// naive DP (TLE)
/*
				for(int j=i+1;j<n;j++){
					if(a[j]-(j-i)==b[i]){
						if(b[i+1]==a[j]-(j-i-1)){
							dp[t][i]=min(dp[t][i],dp[t][i+1]+1);
						}
						else{
							dp[t][i]=min(dp[t][i],dp[t][i+1]+(j-i));
						}
					}
				}
*/
			}

			f[a[i]-i]=i;
		}

		rep(i,n){
			a[i]*=-1;
			b[i]*=-1;
		}
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
	}

	lint res=INF;
	rep(i,n+1){
		res=min(res,dp[0][i]+dp[1][n-i]);
	}
	return res;
}

int main(){
	int n,l; scanf("%d%d",&n,&l);
	vector<int> a(n+2),b(n+2);
	rep(i,n) scanf("%d",&a[i+1]);
	rep(i,n) scanf("%d",&b[i+1]);
	a[n+1]=l+1;
	b[n+1]=l+1;
	n+=2;

	vector<int> P;
	rep(i,n) if(a[i]==b[i]) P.emplace_back(i);

	lint ans=0;
	rep(i,P.size()-1){
		int l=P[i],r=P[i+1]+1;
		vector<int> a2(r-l),b2(r-l);
		rep(j,r-l){
			a2[j]=a[l+j];
			b2[j]=b[l+j];
		}

		lint tmp=solve(a2,b2);
		if(tmp==INF){
			puts("-1");
			return 0;
		}
		ans+=tmp;
	}
	printf("%lld\n",ans);

	return 0;
}
