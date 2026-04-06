#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string a,b; cin>>a>>b;

	cout<<(a==b?"EQUAL":make_pair(a.length(),a)>make_pair(b.length(),b)?"GREATER":"LESS")<<endl;

	return 0;
}
