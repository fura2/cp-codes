#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	bool f[128]={};
	for(char c:s) f[c]=true;

	for(char c='a';c<='z';c++) if(!f[c]) return cout<<c<<endl,0;
	cout<<"None"<<endl;

	return 0;
}
