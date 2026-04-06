#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int ans=0;
	rep(i,n){
		bool f1[128]={},f2[128]={};
		rep(j,n){
			if(j<i) f1[s[j]]=true;
			else    f2[s[j]]=true;
		}
		int cnt=0;
		for(char c='a';c<='z';c++) if(f1[c] && f2[c]) cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;

	return 0;
}
