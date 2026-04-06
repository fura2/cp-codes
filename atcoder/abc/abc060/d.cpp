#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,W,w[100],v[100];
	cin>>n>>W;
	rep(i,n) cin>>w[i]>>v[i];

	vector<lint> V[4];
	rep(i,n) V[w[i]-w[0]].emplace_back(v[i]);

	vector<lint> Vsum[4];
	rep(i,4){
		sort(V[i].rbegin(),V[i].rend());
		Vsum[i].emplace_back(0);
		lint sum=0;
		for(lint a:V[i]) sum+=a, Vsum[i].emplace_back(sum);
	}

	lint ans=0;
	rep(i,V[0].size()+1) rep(j,V[1].size()+1) rep(k,V[2].size()+1) rep(l,V[3].size()+1) {
		if(i*w[0]+j*(w[0]+1)+k*(w[0]+2)+l*(w[0]+3)<=W){
			ans=max(ans,Vsum[0][i]+Vsum[1][j]+Vsum[2][k]+Vsum[3][l]);
		}
	}
	cout<<ans<<endl;

	return 0;
}
