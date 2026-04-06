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

int main(){
	int n; cin>>n;

	int ans=0;
	for(int i=1;i<=n;i+=2) if(divisor(i).size()==8) ans++;
	cout<<ans<<endl;

	return 0;
}
