#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int ans=0,x=0,y=0;
	map<pair<int,int>,int> f;
	rep(i,n+1){
		ans+=f[make_pair(x,y)];
		++f[make_pair(x,y)];
		if(i<n){
			if(s[i]=='A') x++;
			if(s[i]=='T') x--;
			if(s[i]=='G') y++;
			if(s[i]=='C') y--;
		}
	}
	printf("%d\n",ans);

	return 0;
}
