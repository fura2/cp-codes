#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	map<string,int> f;
	f["Sunday"]=0;
	f["Monday"]=5;
	f["Tuesday"]=4;
	f["Wednesday"]=3;
	f["Thursday"]=2;
	f["Friday"]=1;
	f["Saturday"]=0;

	string s; cin>>s; cout<<f[s]<<endl;

	return 0;
}
