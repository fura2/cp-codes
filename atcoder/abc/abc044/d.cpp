#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<lint> divisor(lint a){
	vector<lint> res;
	for(lint i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	return res;
}

lint f(lint b,lint n){ return n<b?n:f(b,n/b)+n%b; }

lint solve(lint n,lint s){
	if(n< s) return -1;
	if(n==s) return n+1;

	for(lint b=2;b*b<=n;b++) if(f(b,n)==s) return b;

	// n = p * b + q, s = p + q
	// => n - s = p * (b - 1)
	lint res=LLONG_MAX;
	auto D=divisor(n-s);
	for(lint d:D){
		lint b=d+1;
		lint p=(n-s)/(b-1);
		lint q=s-p;
		if(1<=p && p<b && 0<=q && q<b) res=min(res,b);
	}
	return res<LLONG_MAX?res:-1;
}

int main(){
	lint n,s; cin>>n>>s;
	cout<<solve(n,s)<<endl;
	return 0;
}
