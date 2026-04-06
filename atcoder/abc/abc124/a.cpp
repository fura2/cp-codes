#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	if(a==b) cout<<a+b<<endl;
	else cout<<2*max(a,b)-1<<endl;

	return 0;
}
