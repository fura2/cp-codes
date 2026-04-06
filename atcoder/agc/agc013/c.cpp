#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const double EPS=1e-3;

int main(){
	int n;
	lint L,T; scanf("%d%lld%lld",&n,&L,&T);
	vector<int> x(n),dir(n);
	rep(i,n) scanf("%d%d",&x[i],&dir[i]);

	lint cnt=0;
	rep(i,n) if(dir[0]!=dir[i]) {
		lint d;
		if(dir[0]==1) d=x[i]-x[0];
		else          d=L-(x[i]-x[0]);

		if(2*(T-0.1)>d){
			cnt+=1+(2*(T-0.1)-d)/L;
		}
	}

	vector<double> pos(n);
	rep(i,n){
		if(dir[i]==1){
			pos[i]=(x[i]+T)%L;
			pos[i]-=0.1;
			if(pos[i]<0) pos[i]+=L;
		}
		else{
			pos[i]=(x[i]-T%L+L)%L;
			pos[i]+=0.1;
		}
	}
	double goal=pos[0];
	sort(pos.begin(),pos.end());
	int i_goal;
	rep(i,n) if(abs(pos[i]-goal)<EPS) i_goal=i;

	int idx;
	if(dir[0]==1){
		idx=cnt%n;
	}
	else{
		idx=(-cnt)%n;
		if(idx<0) idx+=n;
	}

	vector<double> ans(n);
	ans[idx]=goal;
	rep(i,n){
		ans[idx]=pos[i_goal];
		idx=(idx+1)%n;
		i_goal=(i_goal+1)%n;
	}

	rep(i,n) printf("%.0f\n",ans[i]);

	return 0;
}
