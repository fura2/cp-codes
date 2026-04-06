#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

map<long long,int> prime_factorize(long long a){
	map<long long,int> res;
	if(a%2==0){
		int cnt=0;
		do{ cnt++; a/=2; }while(a%2==0);
		res.emplace(2,cnt);
	}
	for(long long p=3;p*p<=a;p+=2) if(a%p==0) {
		int cnt=0;
		do{ cnt++; a/=p; }while(a%p==0);
		res.emplace(p,cnt);
	}
	if(a>1) res.emplace(a,1);
	return res;
}

int main(){
	lint n; cin>>n;

	lint res=1;
	for(auto pf:prime_factorize(n)){
		lint sum=0,q=1;
		rep(_,pf.second+1) sum+=q, q*=pf.first;
		res*=sum;
	}
	res-=n;
	cout<<(res==n?"Perfect":res<n?"Deficient":"Abundant")<<'\n';

	return 0;
}
