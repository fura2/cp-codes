#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int x,y,z; scanf("%d%d%d",&x,&y,&z);
	int n=x+y+z;
	vector<lint> a(n),b(n),c(n);
	rep(i,n) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);

	{
		vector<tuple<lint,lint,lint>> t(n);
		rep(i,n) t[i]={a[i],b[i],c[i]};
		sort(t.begin(),t.end(),[&](const auto& x,const auto& y){
			return get<0>(x)-get<1>(x)<get<0>(y)-get<1>(y);
		});
		rep(i,n) tie(a[i],b[i],c[i])=t[i];
	}

	vector<lint> res1(n,-INF);
	lint sum=0;
	priority_queue<lint> Q;
	rep(i,y){
		sum+=b[i];
		Q.emplace(c[i]-b[i]);
	}
	res1[y-1]=sum;
	for(int i=y;i<y+z;i++){
		sum+=b[i];
		Q.emplace(c[i]-b[i]);
		sum+=Q.top(); Q.pop();
		res1[i]=sum;
	}

	vector<lint> res2(n,-INF);
	sum=0;
	Q=priority_queue<lint>();
	for(int i=n-1;i>=n-x;i--){
		sum+=a[i];
		Q.emplace(c[i]-a[i]);
	}
	res2[n-x]=sum;
	for(int i=n-x-1;i>=n-x-z;i--){
		sum+=a[i];
		Q.emplace(c[i]-a[i]);
		sum+=Q.top(); Q.pop();
		res2[i]=sum;
	}

	lint ans=-INF;
	rep(i,n-1) ans=max(ans,res1[i]+res2[i+1]);
	printf("%lld\n",ans);

	return 0;
}
