#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int n,d[100000];
lint x[100000],y[100000];

lint fx(lint t){
	lint xl=INF,xr=-INF;
	rep(i,n){
		xl=min(xl,x[i]+t*dx[d[i]]);
		xr=max(xr,x[i]+t*dx[d[i]]);
	}
	return xr-xl;
}

lint fy(lint t){
	lint yl=INF,yr=-INF;
	rep(i,n){
		yl=min(yl,y[i]+t*dy[d[i]]);
		yr=max(yr,y[i]+t*dy[d[i]]);
	}
	return yr-yl;
}

int main(){
	scanf("%d",&n);
	rep(i,n){
		char c; scanf("%lld%lld %c",x+i,y+i,&c);
		x[i]*=2;
		y[i]*=2;
		if     (c=='R') d[i]=0;
		else if(c=='U') d[i]=1;
		else if(c=='L') d[i]=2;
		else            d[i]=3;
	}

	vector<lint> T={0,INF};
	lint lo,hi;
	lo=0; hi=INF;
	while(hi-lo>1){
		lint mi1=(2*lo+hi+1)/3,mi2=(lo+2*hi)/3;
		if(fx(mi1)<=fx(mi2)) hi=mi2;
		else                 lo=mi1;
	}
	T.emplace_back(lo);

	hi=INF;
	while(hi-lo>1){
		lint mi1=(2*lo+hi+1)/3,mi2=(lo+2*hi)/3;
		if(fx(mi1)<fx(mi2)) hi=mi2;
		else                lo=mi1;
	}
	T.emplace_back(lo);

	lo=0; hi=INF;
	while(hi-lo>1){
		lint mi1=(2*lo+hi+1)/3,mi2=(lo+2*hi)/3;
		if(fy(mi1)<=fy(mi2)) hi=mi2;
		else                 lo=mi1;
	}
	T.emplace_back(lo);

	hi=INF;
	while(hi-lo>1){
		lint mi1=(2*lo+hi+1)/3,mi2=(lo+2*hi)/3;
		if(fy(mi1)<fy(mi2)) hi=mi2;
		else                lo=mi1;
	}
	T.emplace_back(lo);
	sort(T.begin(),T.end());

	double ans=1e30;
	rep(i,(int)T.size()-1){
		lo=T[i]; hi=T[i+1];
		while(hi-lo>1){
			lint mi1=(2*lo+hi+1)/3,mi2=(lo+2*hi)/3;
			double x1=fx(mi1);
			double x2=fx(mi2);
			double y1=fy(mi1);
			double y2=fy(mi2);
			if(x1*y1<x2*y2) hi=mi2;
			else            lo=mi1;
		}
		ans=min(ans,1.*fx(lo)*fy(lo));
		ans=min(ans,1.*fx(hi)*fy(hi));
	}
	ans/=4;
	printf("%.15f\n",ans);

	return 0;
}
