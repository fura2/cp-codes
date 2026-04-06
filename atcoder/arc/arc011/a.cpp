#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m,n,N; cin>>m>>n>>N;
	int ans=N;
	while(N>=m){
		ans+=N/m*n;
		N=N%m+N/m*n;
	}
	cout<<ans<<endl;

	return 0;
}
