#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,p[1000]; cin>>n;
	string s[1000];
	rep(i,n) cin>>s[i]>>p[i];

	int sum=accumulate(p,p+n,0);
	rep(i,n) if(2*p[i]>sum) return (cout<<s[i]<<'\n'),0;
	cout<<"atcoder"<<'\n';

	return 0;
}
