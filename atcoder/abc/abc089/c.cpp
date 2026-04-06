#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; cin>>n;

	lint cnt[5]={};
	rep(i,n){
		string s; cin>>s;
		if(s[0]=='M') cnt[0]++;
		if(s[0]=='A') cnt[1]++;
		if(s[0]=='R') cnt[2]++;
		if(s[0]=='C') cnt[3]++;
		if(s[0]=='H') cnt[4]++;
	}

	lint ans=0;
	int p[]={0,0,1,1,1};
	do{
		int idx[3],n=0;
		rep(i,5) if(p[i]==1) idx[n++]=i;
		ans+=cnt[idx[0]]*cnt[idx[1]]*cnt[idx[2]];
	}while(next_permutation(p,p+5));
	cout<<ans<<endl;

	return 0;
}
