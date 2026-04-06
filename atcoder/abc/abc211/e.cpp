#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using ulint=unsigned long long;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int n,rem;
string B[8];

set<ulint> ans;
vector<pair<int,int>> H;

void dfs(ulint S,int t){
	if(H.size()==rem){
		ans.emplace(S);
		return;
	}

	for(;t<H.size();t++){
		auto [i,j]=H[t];
		rep(k,4){
			int x=i+dx[k],y=j+dy[k];
			if(0<=x && x<n && 0<=y && y<n && B[x][y]=='.'){
				H.emplace_back(x,y);
				B[x][y]='x';
				dfs(S|(1LL<<(x*n+y)),t);
				B[x][y]='.';
				H.pop_back();
			}
		}
	}
}

int main(){
	cin>>n>>rem;
	rep(i,n) cin>>B[i];

	rep(i,n) rep(j,n) if(B[i][j]=='.') {
		H.emplace_back(i,j);
		B[i][j]='x';
		dfs(1LL<<(i*n+j),0);
		B[i][j]='.';
		H.pop_back();
	}
	cout<<ans.size()<<'\n';

	return 0;
}
