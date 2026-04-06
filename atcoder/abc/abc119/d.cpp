#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int main(){
	int a,b,q; scanf("%d%d%d",&a,&b,&q);
	lint s[100004],t[100004];
	rep(i,a) scanf("%lld",s+i+2);
	rep(i,b) scanf("%lld",t+i+2);
	s[0]=t[0]=-2*INF;
	s[1]=t[1]=-INF;
	s[a+2]=t[b+2]=INF;
	s[a+3]=t[b+3]=2*INF;
	a+=4;
	b+=4;

	rep(_,q){
		lint x; scanf("%lld",&x);
		lint ans=INF;
		{
			auto it=lower_bound(s,s+a,x);
			lint next[2]={*it,*prev(it)};
			for(lint y:next){
				auto jt=lower_bound(t,t+b,y);
				ans=min(ans,abs(y-x)+min(abs(*jt-y),abs(*prev(jt)-y)));
			}
		}
		{
			auto it=lower_bound(t,t+b,x);
			lint next[2]={*it,*prev(it)};
			for(lint y:next){
				auto jt=lower_bound(s,s+a,y);
				ans=min(ans,abs(y-x)+min(abs(*jt-y),abs(*prev(jt)-y)));
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
