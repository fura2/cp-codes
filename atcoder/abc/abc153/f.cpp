#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,d,a; scanf("%lld%lld%lld",&n,&d,&a);
	vector<pair<lint,lint>> mon(n);
	rep(i,n){
		lint x,hp; scanf("%lld%lld",&x,&hp);
		mon[i]={x,hp};
	}

	sort(mon.begin(),mon.end());

	lint ans=0,power=0;
	queue<pair<lint,lint>> Q; // rightmost point, damage
	rep(i,n){
		lint x,hp; tie(x,hp)=mon[i];

		while(!Q.empty() && Q.front().first<=x){
			power-=Q.front().second;
			Q.pop();
		}

		if(power>=hp) continue;

		lint cnt=(hp-power+a-1)/a;
		ans+=cnt;
		power+=cnt*a;
		Q.emplace(x+2*d+1,cnt*a);
	}
	printf("%lld\n",ans);

	return 0;
}
