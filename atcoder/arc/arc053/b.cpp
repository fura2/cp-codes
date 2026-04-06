#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int hist[128]={};
	for(char c:s) hist[c]++;

	int odd=0;
	rep(c,128) if(hist[c]%2==1) odd++;

	if(odd==0) cout<<s.length()<<'\n';
	else       cout<<(s.length()-odd)/2/odd*2+1<<'\n';

	return 0;
}
