#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint f(lint h){ return h==1?1:2*f(h/2)+1; }

int main(){
	lint h; cin>>h;
	cout<<f(h)<<'\n';
	return 0;
}
