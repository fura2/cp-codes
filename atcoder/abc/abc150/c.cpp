#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<int> a(n),p(n),q(n);
	iota(a.begin(),a.end(),1);
	rep(i,n) cin>>p[i];
	rep(i,n) cin>>q[i];

	int cnt=0,res1,res2;
	do{
		if(a==p) res1=cnt;
		if(a==q) res2=cnt;
		cnt++;
	}while(next_permutation(a.begin(),a.end()));
	cout<<abs(res1-res2)<<'\n';

	return 0;
}
