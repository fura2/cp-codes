#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	string B[100];
	rep(i,h) cin>>B[i];

	bool fr[100]={},fc[100]={};
	rep(i,h){
		fr[i]=true;
		rep(j,w) if(B[i][j]=='#') fr[i]=false;
	}
	rep(j,w){
		fc[j]=true;
		rep(i,h) if(B[i][j]=='#') fc[j]=false;
	}

	rep(i,h) if(!fr[i]) {
		rep(j,w) if(!fc[j]) cout<<B[i][j];
		cout<<endl;
	}

	return 0;
}
