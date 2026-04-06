#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool isover(string B[19],char c){
	rep(i,19) rep(j,15) {
		bool ok=true;
		rep(k,5) if(B[i][j+k]!=c) ok=false;
		if(ok) return true;
	}
	rep(i,15) rep(j,19) {
		bool ok=true;
		rep(k,5) if(B[i+k][j]!=c) ok=false;
		if(ok) return true;
	}
	rep(i,15) rep(j,15) {
		bool ok=true;
		rep(k,5) if(B[i+k][j+k]!=c) ok=false;
		if(ok) return true;
	}
	rep(i,15) rep(j,15) {
		bool ok=true;
		rep(k,5) if(B[i+k][j-k+4]!=c) ok=false;
		if(ok) return true;
	}
	return false;
}

int main(){
	string B[19];
	rep(i,19) cin>>B[i];

	int nb=0,nw=0;
	rep(i,19) rep(j,19) {
		if(B[i][j]=='o') nb++;
		if(B[i][j]=='x') nw++;
	}

	if(nb==0 && nw==0){
		cout<<"YES"<<endl;
		return 0;
	}
	else if(nb==nw+1){
		rep(i,19) rep(j,19) if(B[i][j]=='o') {
			B[i][j]='.';
			if(!isover(B,'o') && !isover(B,'x')){ cout<<"YES"<<endl; return 0; }
			B[i][j]='o';
		}
	}
	else if(nb==nw){
		rep(i,19) rep(j,19) if(B[i][j]=='x') {
			B[i][j]='.';
			if(!isover(B,'o') && !isover(B,'x')){ cout<<"YES"<<endl; return 0; }
			B[i][j]='x';
		}
	}

	cout<<"NO"<<endl;

	return 0;
}
