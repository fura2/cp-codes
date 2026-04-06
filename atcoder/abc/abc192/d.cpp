#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s;
	lint m; cin>>s>>m;

	int n=s.length(),d=0;
	rep(i,n) d=max<int>(d,s[i]-'0');

	if(n==1){
		puts(d<=m?"1":"0");
		return 0;
	}

	lint lo=d,hi=m+1;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		bool ok=true;
		__int128 tmp=0;
		rep(i,n){
			tmp=mi*tmp+(s[i]-'0');
			if(tmp>m) break;
		}
		if(tmp<=m) lo=mi;
		else       hi=mi;
	}
	printf("%lld\n",lo-d);

	return 0;
}
