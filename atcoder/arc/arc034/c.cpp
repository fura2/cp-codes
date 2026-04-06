#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

map<lint,int> prime_factorize(lint a){
	map<lint,int> res;
	if(a%2==0){
		int cnt=0;
		do{ cnt++; a/=2; }while(a%2==0);
		res.emplace(2,cnt);
	}
	for(lint p=3;p*p<=a;p+=2) if(a%p==0) {
		int cnt=0;
		do{ cnt++; a/=p; }while(a%p==0);
		res.emplace(p,cnt);
	}
	if(a>1) res.emplace(a,1);
	return res;
}

int main(){
	lint a,b; cin>>a>>b;

	map<lint,int> f;
	for(lint c=b+1;c<=a;c++){
		for(auto p:prime_factorize(c)) f[p.first]+=p.second;
	}

	lint ans=1;
	for(auto p:f) ans=ans*(p.second+1)%1000000007;
	cout<<ans<<'\n';

	return 0;
}
