#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint nb[51],np[51];

lint solve(int n,lint x){
	if(n==0) return 1;

	if(x<=1)
		return 0;
	else if(x<=1+nb[n-1]+np[n-1])
		return solve(n-1,x-1);
	else if(x<=1+nb[n-1]+np[n-1]+1)
		return np[n-1]+1;
	else if(x<=1+nb[n-1]+np[n-1]+1+nb[n-1]+np[n-1])
		return solve(n-1,x-(1+nb[n-1]+np[n-1]+1))+1+np[n-1];
	else
		return np[n];
}

int main(){
	np[0]=1;
	rep(i,50) nb[i+1]=1+nb[i]+nb[i]+1, np[i+1]=np[i]+1+np[i];

	int n;
	lint x; cin>>n>>x;
	cout<<solve(n,x)<<endl;

	return 0;
}
