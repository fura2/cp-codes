#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int n; cin>>s>>n;
	rep(i,n){
		int l,r; cin>>l>>r; l--;
		reverse(s.begin()+l,s.begin()+r);
	}
	cout<<s<<'\n';
	return 0;
}
