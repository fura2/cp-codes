#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int hist[128]={};
	for(char c:s) hist[c]++;

	bool ok=true;
	rep(c,128) if(hist[c]%2==1) ok=false;
	cout<<(ok?"Yes":"No")<<'\n';

	return 0;
}
