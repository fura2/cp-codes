#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }
template<class T> T lcm(const T& a,const T& b){ return a/gcd(a,b)*b; }

int main(){
	lint n,m;
	string s,t; cin>>n>>m>>s>>t;

	if(n>m){
		swap(n,m);
		swap(s,t);
	}

	lint g=gcd(n,m);
	rep(i,g) if(s[n/g*i]!=t[m/g*i]) return puts("-1"),0;
	cout<<lcm(n,m)<<'\n';

	return 0;
}
