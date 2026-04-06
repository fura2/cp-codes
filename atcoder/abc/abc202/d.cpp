#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<vector<long long>> binomial_table(int n){
	vector C(n+1,vector(n+1,0LL));
	rep(i,n+1){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	return C;
}

int main(){
	auto nCr=binomial_table(60);

	int a,b;
	lint k; cin>>a>>b>>k;

	string ans;
	int x=a,y=b;
	rep(i,a+b){
		if(x==0){
			ans+='b';
			y--;
		}
		else if(y==0){
			ans+='a';
			x--;
		}
		else{
			if(nCr[x+y-1][y]<k){
				k-=nCr[x+y-1][y];
				ans+='b';
				y--;
			}
			else{
				ans+='a';
				x--;
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}
