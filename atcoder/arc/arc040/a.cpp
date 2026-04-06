#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	string B[100];
	rep(i,n) cin>>B[i];

	int cnt=0;
	rep(i,n) rep(j,n) {
		if(B[i][j]=='R') cnt++;
		if(B[i][j]=='B') cnt--;
	}
	puts(cnt>0?"TAKAHASHI":cnt==0?"DRAW":"AOKI");

	return 0;
}
