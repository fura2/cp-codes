#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k;
	vector<vector<int>> B(2*k+1,vector<int>(2*k+1));
	rep(i,n){
		int x,y;
		char c; cin>>x>>y>>c;
		if(c=='W') y+=k;
		B[y%(2*k)+1][x%(2*k)+1]++;
	}
	rep(i,2*k) rep(j,2*k) B[i+1][j+1]+=B[i+1][j]+B[i][j+1]-B[i][j];

	int ans=0;
	rep(i,k+1) rep(j,k+1) {
		int cnt=0;
		cnt+=B[k+i][k+j]-B[i][k+j]-B[k+i][j]+B[i][j];
		cnt+=B[2*k][2*k]-B[k+i][2*k]-B[2*k][k+j]+B[k+i][k+j];
		cnt+=B[i][j];
		cnt+=B[i][2*k]-B[i][k+j];
		cnt+=B[2*k][j]-B[k+i][j];
		ans=max({ans,cnt,n-cnt});
	}
	cout<<ans<<endl;

	return 0;
}
