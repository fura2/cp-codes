#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x[10][5]; // x[a][i] = a^i mod 10
	rep(a,10){
		x[a][0]=1;
		rep(i,4) x[a][i+1]=x[a][i]*a%10;
	}

	lint y[4][3]; // y[b][i] = b^i mod 4
	rep(b,4){
		y[b][0]=1;
		rep(i,2) y[b][i+1]=y[b][i]*b%4;
	}

	lint a,b,c; cin>>a>>b>>c;

	lint e; // b^c mod 4
	if(b%4==2) e=(c==1?2:0);
	else       e=y[b%4][c%2==0?2:c%2];

	cout<<x[a%10][e==0?4:e]<<'\n';

	return 0;
}
