#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string B[8];

bool is_OK(int i,int j){
	rep(y,8) if(y!=i && B[y][j]=='Q') return false;
	rep(x,8) if(x!=j && B[i][x]=='Q') return false;
	for(int k=-8;k<8;k++) if(k!=0) {
		if(0<=i+k && i+k<8 && 0<=j+k && j+k<8 && B[i+k][j+k]=='Q') return false;
		if(0<=i+k && i+k<8 && 0<=j-k && j-k<8 && B[i+k][j-k]=='Q') return false;
	}
	return true;
}

bool dfs(int i){
	if(i==8) return true;

	if(count(B[i].begin(),B[i].end(),'Q')==1) return dfs(i+1);

	rep(j,8) if(is_OK(i,j)) {
		B[i][j]='Q';
		if(dfs(i+1)) return true;
		B[i][j]='.';
	}
	return false;
}

int main(){
	rep(i,8) cin>>B[i];

	bool ok=true;
	rep(i,8) rep(j,8) if(B[i][j]=='Q' && !is_OK(i,j)) ok=false;

	if(!ok || !dfs(0)){
		cout<<"No Answer\n";
	}
	else{
		rep(i,8) cout<<B[i]<<'\n';
	}

	return 0;
}
