#include <algorithm>
#include <iostream>
#include <map>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s[100000];
	cin>>n;
	rep(i,n) cin>>s[i], sort(s[i].begin(),s[i].end());

	map<string,int> f;
	rep(i,n) ++f[s[i]];

	long long ans=0;
	for(auto a:f) ans+=a.second*(a.second-1LL)/2;
	cout<<ans<<endl;

	return 0;
}
