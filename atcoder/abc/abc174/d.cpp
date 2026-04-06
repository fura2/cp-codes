#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	vector<int> cum1(n+1),cum2(n+1);
	rep(i,n){
		cum1[i+1]=cum1[i]+(s[i]=='R'?1:0);
		cum2[i+1]=cum2[i]+(s[i]=='W'?1:0);
	}

	int ans=n;
	rep(i,n+1){
		ans=min(ans,max(cum2[i],cum1[n]-cum1[i]));
	}
	printf("%d\n",ans);

	return 0;
}
