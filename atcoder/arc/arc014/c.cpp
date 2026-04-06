#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int hist[128]={};
	for(char c:s) hist[c]++;

	cout<<(hist['R']%2+hist['G']%2+hist['B']%2)<<'\n';

	return 0;
}
