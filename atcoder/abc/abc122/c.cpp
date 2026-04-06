#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q;
	string s; cin>>n>>q>>s;

	int sum[100001]={};
	rep(i,n-1) if(s[i]=='A' && s[i+1]=='C') sum[i+1]++;
	rep(i,n) sum[i+1]+=sum[i];

	rep(_,q){
		int l,r; cin>>l>>r; l--;
		int ans=sum[r]-sum[l];
		if(r<n && s[r-1]=='A' && s[r]=='C') ans--;
		cout<<ans<<endl;
	}

	return 0;
}
