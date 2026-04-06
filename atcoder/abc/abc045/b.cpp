#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string a[3];
	rep(i,3) cin>>a[i];

	int t=0,idx[3]={};
	while(idx[t]<a[t].size()) t=a[t][idx[t]++]-'a';
	cout<<(char)('A'+t)<<'\n';

	return 0;
}
