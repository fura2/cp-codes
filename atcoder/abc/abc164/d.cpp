#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s; cin>>s;
	int n=s.length();

	map<int,int> f;
	int sum=0,ten=1;
	for(int i=n-1;i>=0;i--){
		sum=((s[i]-'0')*ten+sum)%2019;
		ten=ten*10%2019;
		++f[sum];
	}

	lint ans=0;
	sum=0; ten=1;
	for(int i=n-1;i>=0;i--){
		ans+=f[sum];
		sum=((s[i]-'0')*ten+sum)%2019;
		ten=ten*10%2019;
		--f[sum];
	}
	printf("%lld\n",ans);

	return 0;
}
