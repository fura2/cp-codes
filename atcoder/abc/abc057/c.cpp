#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<lint> divisors(lint a){
	vector<lint> res;
	for(lint i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	return res;
}

int main(){
	lint n; cin>>n;

	int ans=20;
	for(lint d:divisors(n)){
		ans=min<int>(ans,max(to_string(d).length(),to_string(n/d).length()));
	}
	cout<<ans<<endl;

	return 0;
}
