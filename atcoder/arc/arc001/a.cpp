#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int c1=count(s.begin(),s.end(),'1');
	int c2=count(s.begin(),s.end(),'2');
	int c3=count(s.begin(),s.end(),'3');
	int c4=count(s.begin(),s.end(),'4');
	cout<<max({c1,c2,c3,c4})<<' '<<min({c1,c2,c3,c4})<<'\n';

	return 0;
}
