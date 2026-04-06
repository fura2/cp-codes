#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> x(n),y(n);
	rep(i,n) scanf("%lld%lld",&x[i],&y[i]);

	vector<lint> u(n),v(n);
	rep(i,n){
		u[i]=x[i]+y[i];
		v[i]=x[i]-y[i];
	}

	lint u_min=*min_element(u.begin(),u.end());
	lint u_max=*max_element(u.begin(),u.end());
	lint v_min=*min_element(v.begin(),v.end());
	lint v_max=*max_element(v.begin(),v.end());

	lint d=max(u_max-u_min,v_max-v_min);
	assert(d%2==0);

	lint T[]={v_min,v_max-d};
	lint L[]={u_min,u_max-d};
	rep(i,2) rep(j,2) {
		lint t=T[i],l=L[j];
		lint b=t+d,r=l+d;

		bool ok=true;
		rep(k,n){
			bool tmp=false;
			if(l<=u[k] && u[k]<=r && (v[k]==t || v[k]==b)) tmp=true;
			if(t<=v[k] && v[k]<=b && (u[k]==l || u[k]==r)) tmp=true;
			if(!tmp) ok=false;
		}
		if(ok){
			lint u0=l+d/2,v0=t+d/2;
			printf("%lld %lld\n",(u0+v0)/2,(u0-v0)/2);
			return 0;
		}
	}
	assert(0);

	return 0;
}
