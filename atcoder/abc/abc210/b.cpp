#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	rep(i,n) if(s[i]=='1') {
		cout<<(i%2==0?"Takahashi":"Aoki")<<'\n';
		break;
	}
	return 0;
}
