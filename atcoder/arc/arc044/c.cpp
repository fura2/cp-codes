#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int solve(int w,const vector<pair<int,int>>& Ev){
	vector<int> X[100001];
	for(auto e:Ev) X[e.first].emplace_back(e.second);

	vector<int> dp(w);
	rep(t,1e5+1) if(!X[t].empty()) {
		sort(X[t].begin(),X[t].end());
		int pre=X[t][0];
		rep(i,X[t].size()) if(i+1==X[t].size() || X[t][i]+1<X[t][i+1]) {
			int l=pre,r=X[t][i]+1;
			for(int j=l;j<r;j++){
				if(l>0) dp[l-1]=min(dp[l-1],dp[j]+j-l+1);
				if(r<w) dp[ r ]=min(dp[ r ],dp[j]+r-j);
				dp[j]=INF;
			}
			pre=X[t][i+1];
		}
	}
	return *min_element(dp.begin(),dp.end());
}

int main(){
	int w,h,q; scanf("%d%d%d",&w,&h,&q);

	vector<pair<int,int>> Ev[2];
	rep(i,q){
		int t,d,x; scanf("%d%d%d",&t,&d,&x); x--;
		Ev[d].emplace_back(t,x);
	}

	int ans=solve(w,Ev[0])+solve(h,Ev[1]);
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
