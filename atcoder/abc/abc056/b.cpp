#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int w,a,b; cin>>w>>a>>b;
	if     (a+w<b) cout<<b-(a+w)<<'\n';
	else if(b+w<a) cout<<a-(b+w)<<'\n';
	else           cout<<0<<'\n';
	return 0;
}
