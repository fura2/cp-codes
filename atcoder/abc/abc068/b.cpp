#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

using namespace std;

int main(){
	int n; cin>>n;

	int m;
	for(m=0;(1<<m)<=n;m++);
	cout<<(1<<(m-1))<<endl;

	return 0;
}
