#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	lint h;
	int n; scanf("%lld%d",&h,&n);
	vector<lint> r(n+1),d(n);
	rep(i,n) scanf("%lld",&r[i+1]);
	rep(i,n) d[i]=r[i+1]-r[i];

	int q; scanf("%d",&q);
	vector<lint> T(q),a(q);
	rep(i,q) scanf("%lld%lld",&T[i],&a[i]);

	// t_sat0[i] = (初期値 a[i] で始めたときに y = 0 で saturate する時刻)
	// t_sat1[i] = (初期値 a[i] で始めたときに y = h で saturate する時刻)
	vector<lint> t_sat0(q,INF),t_sat1(q,INF);
// t_sat0, t_sat1 の愚直計算 O(NQ)
/*
	rep(i,q){
		lint y=a[i];
		rep(j,n){
			if(j%2==0){
				if(y-d[j]<=0){
					t_sat0[i]=r[j]+y;
					break;
				}
				y-=d[j];
			}
			else{
				if(y+d[j]>=h){
					t_sat1[i]=r[j]+(h-y);
					break;
				}
				y+=d[j];
			}
		}
	}
*/
	{ // t_sat0 の計算
		vector<int> p(q);
		iota(p.begin(),p.end(),0);
		sort(p.begin(),p.end(),[&](int i,int j){
			return a[i]<a[j];
		});

		int j=0;
		lint y=a[p[0]];
		rep(i,q){
			if(i>0) y+=a[p[i]]-a[p[i-1]];

			for(;j<n;j++){
				if(j%2==0){
					if(y-d[j]<=0){
						t_sat0[p[i]]=r[j]+y;
						break;
					}
					y-=d[j];
				}
				else{
					y+=d[j];
				}
			}
		}
	}
	{ // t_sat1 の計算
		vector<int> p(q);
		iota(p.begin(),p.end(),0);
		sort(p.begin(),p.end(),[&](int i,int j){
			return a[i]>a[j];
		});

		int j=0;
		lint y=a[p[0]];
		rep(i,q){
			if(i>0) y+=a[p[i]]-a[p[i-1]];

			for(;j<n;j++){
				if(j%2==0){
					y-=d[j];
				}
				else{
					if(y+d[j]>=h){
						t_sat1[p[i]]=r[j]+(h-y);
						break;
					}
					y+=d[j];
				}
			}
		}
	}

	// cum[i] = (saturate しないとしたときの t = r[i] での砂の量)
	vector<lint> cum(n+1);
	rep(i,n){
		if(i%2==0) cum[i+1]=cum[i]-d[i];
		else       cum[i+1]=cum[i]+d[i];
	}

	// sol0[i] = (初期値 a = 0 で始めたときの t = r[i] での砂の量)
	// sol1[i] = (初期値 a = h で始めたときの t = r[i] での砂の量)
	vector<lint> sol0(n+1),sol1(n+1);
	sol1[0]=h;
	rep(i,n){
		if(i%2==0){
			sol0[i+1]=max(sol0[i]-d[i],0LL);
			sol1[i+1]=max(sol1[i]-d[i],0LL);
		}
		else{
			sol0[i+1]=min(sol0[i]+d[i],h);
			sol1[i+1]=min(sol1[i]+d[i],h);
		}
	}

	rep(i,q){
		int idx=upper_bound(r.begin(),r.end(),T[i])-r.begin()-1;
		lint ans;
		if(T[i]<=min(t_sat0[i],t_sat1[i])){
			ans=a[i]+cum[idx];
		}
		else{
			if(t_sat0[i]<=t_sat1[i]){
				ans=sol0[idx];
			}
			else{
				ans=sol1[idx];
			}
		}
		if(idx%2==0) ans=max(ans-(T[i]-r[idx]),0LL);
		else         ans=min(ans+(T[i]-r[idx]),h);
		printf("%lld\n",ans);
	}

	return 0;
}
