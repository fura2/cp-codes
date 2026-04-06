#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int ans=n;
	rep(i,4) rep(j,4) rep(k,4) rep(l,4) {
		int cnt=0;
		rep(t,n){
			if     (t+1<n && s[t]=="ABXY"[i] && s[t+1]=="ABXY"[j]) t++;
			else if(t+1<n && s[t]=="ABXY"[k] && s[t+1]=="ABXY"[l]) t++;
			cnt++;
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;

	return 0;
}
