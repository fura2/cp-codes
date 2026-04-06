#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b; cin>>n>>a>>b;
	vector<int> c(n);
	rep(i,n) cin>>c[i];

	rep(i,n) if(a+b==c[i]) cout<<i+1<<endl;

	return 0;
}
