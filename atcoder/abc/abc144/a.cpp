#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	cout<<(a<10&&b<10?a*b:-1)<<endl;
	return 0;
}
