#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1e9+7;

int main(){
	int n;
	string B[2]; cin>>n>>B[0]>>B[1];

	int ans,i=0;
	while(i<n){
		if(B[0][i]==B[1][i]){
			if(i==0) ans=3;
			else if(B[0][i-1]==B[1][i-1]) ans=ans*2%MOD;
			i++;
		}
		else{
			if(i==0) ans=6;
			else if(B[0][i-1]==B[1][i-1]) ans=ans*2%MOD;
			else ans=ans*3LL%MOD;
			i+=2;
		}
	}
	cout<<ans<<endl;

	return 0;
}
