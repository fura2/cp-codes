#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	tuple<string,int,int> r[100];
	rep(i,n) cin>>get<0>(r[i])>>get<1>(r[i]), get<1>(r[i])*=-1, get<2>(r[i])=i;

	sort(r,r+n);

	rep(i,n) cout<<get<2>(r[i])+1<<endl;

	return 0;
}
