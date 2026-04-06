#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int cnt=0,def=0;
	rep(i,n){
		if(s[i]=='(') cnt++;
		else cnt--;
		if(cnt<0) cnt=0, def++;
	}
	cout<<string(def,'(')+s+string(cnt,')')<<endl;

	return 0;
}
