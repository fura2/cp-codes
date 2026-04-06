#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,x,d; cin>>n>>x>>d;

	if(d==0){
		cout<<(x==0?1:n+1)<<'\n';
		return 0;
	}

	if(d<0) d=-d, x=-x;

	map<lint,vector<pair<lint,lint>>> I;
	for(lint m=0;m<=n;m++){
		lint mn=m*(m-1)-n*(n-1)/2;
		lint mx=n*(n-1)/2-(n-m)*(n-m-1);

		lint l=(2*m-n)*x+d*mn;
		lint r=(2*m-n)*x+d*mx;

		int idx=l%(2*d);
		if(idx<0) idx+=2*d;
		I[idx].emplace_back(l,r+1);
	}

	lint ans=0;
	for(auto& p:I){
		auto& J=p.second;
		sort(J.begin(),J.end());
		lint r;
		rep(i,J.size()){
			if(i==0 || r<=J[i].first){
				ans+=(J[i].second-J[i].first+2*d-1)/(2*d);
				r=J[i].second;
			}
			else if(r<J[i].second){
				ans+=(J[i].second-r+2*d-1)/(2*d);
				r=J[i].second;
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}
