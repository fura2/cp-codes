#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int n,W,v[200],w[200];

lint solve1(){
	vector<pair<lint,lint>> P;
	rep(S,1<<n/2){
		lint vsum=0,wsum=0;
		rep(i,n/2) if(S>>i&1) {
			vsum+=v[i];
			wsum+=w[i];
		}
		P.emplace_back(wsum,vsum);
	}

	vector<pair<lint,lint>> Q;
	rep(S,1<<(n-n/2)){
		lint vsum=0,wsum=0;
		rep(i,n-n/2) if(S>>i&1) {
			vsum+=v[n-i-1];
			wsum+=w[n-i-1];
		}
		Q.emplace_back(wsum,vsum);
	}
	sort(Q.begin(),Q.end());
	for(int i=1;i<Q.size();i++) Q[i].second=max(Q[i].second,Q[i-1].second);

	lint res=0;
	for(auto a:P){
		lint wsum,vsum;
		tie(wsum,vsum)=a;
		if(wsum<=W){
			auto it=lower_bound(Q.begin(),Q.end(),make_pair(W-wsum+1,0LL));
			res=max(res,vsum+(--it)->second);
		}
	}
	return res;
}

lint solve2(){
	int wsum=min(accumulate(w,w+n,0),W);
	vector<lint> dp(wsum+1);
	rep(i,n) for(int a=wsum;a>=w[i];a--) dp[a]=max(dp[a],dp[a-w[i]]+v[i]);
	return *max_element(dp.begin(),dp.end());
}

lint solve3(){
	int vsum=accumulate(v,v+n,0);
	vector<lint> dp(vsum+1,INF);
	dp[0]=0;
	rep(i,n) for(int a=vsum;a>=v[i];a--) dp[a]=min(dp[a],dp[a-v[i]]+w[i]);
	lint res=0;
	rep(a,vsum+1) if(dp[a]<=W) res=a;
	return res;
}

int main(){
	cin>>n>>W;
	rep(i,n) cin>>v[i]>>w[i];

	int wmx=*max_element(w,w+n);
	if     (n<=30)     cout<<solve1()<<endl;
	else if(wmx<=1000) cout<<solve2()<<endl;
	else               cout<<solve3()<<endl;

	return 0;
}
