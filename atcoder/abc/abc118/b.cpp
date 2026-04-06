#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;

	int cnt[30]={};
	rep(i,n){
		int k; cin>>k;
		rep(j,k){ int a; cin>>a; a--; cnt[a]++; }
	}

	cout<<count(cnt,cnt+m,n)<<endl;

	return 0;
}
