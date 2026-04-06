#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s; cin>>s;
	int n=s.length();

	lint ans=0;
	rep(i,n){
		if(s[i]=='U') ans+=(n-i-1)+2*i;
		else          ans+=i+2*(n-i-1);
	}
	printf("%lld\n",ans);

	return 0;
}
