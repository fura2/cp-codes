#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; cin>>n>>m;

	int ans1=0,ans2=0;
	vector<bool> ac(n);
	vector<int> cnt(n);
	rep(i,m){
		int p;
		string s; cin>>p>>s; p--;
		if(s=="AC"){
			if(!ac[p]) ans1++, ans2+=cnt[p], ac[p]=true;
		}
		else cnt[p]++;
	}
	cout<<ans1<<' '<<ans2<<'\n';

	return 0;
}
