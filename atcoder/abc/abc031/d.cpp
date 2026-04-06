#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int k,n;
string v[50],w[50];

string ans[10];

bool dfs(int i,int j,int k){ // v[i] の j 文字目, w[i] の k 文字目を見ている
	if(i==n) return true;

	if(j==v[i].length()){
		if(k==w[i].length()) return dfs(i+1,0,0);
		else                 return false;
	}

	int d=v[i][j]-'0';
	if(!ans[d].empty()){
		if(mismatch(w[i].begin()+k,w[i].end(),ans[d].begin(),ans[d].end()).second==ans[d].end()){
			return dfs(i,j+1,k+ans[d].length());
		}
	}
	else{
		rep(t,3){
			if(k+t<w[i].length()){
				ans[d]=w[i].substr(k,t+1);
				if(dfs(i,j+1,k+t+1)) return true;
			}
		}
		ans[d]="";
	}
	return false;
}

int main(){
	cin>>k>>n;
	rep(i,n) cin>>v[i]>>w[i];

	dfs(0,0,0);

	rep(i,k) cout<<ans[i+1]<<'\n';

	return 0;
}
