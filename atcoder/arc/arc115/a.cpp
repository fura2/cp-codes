#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; cin>>n>>m;
	vector<int> a(n);
	rep(i,n){
		string s; cin>>s;
		rep(j,m) if(s[j]=='1') a[i]++;
	}

	lint cnt[2]={};
	rep(i,n) cnt[a[i]%2]++;

	printf("%lld\n",cnt[0]*cnt[1]);

	return 0;
}
