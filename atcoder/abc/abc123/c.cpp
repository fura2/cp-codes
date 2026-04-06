#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,a,b,c,d,e; cin>>n>>a>>b>>c>>d>>e;
	lint m=min({a,b,c,d,e});
	cout<<(n+m-1)/m+4<<endl;

	return 0;
}
