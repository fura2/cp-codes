#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int cnt[6]={};
	for(char c:s) cnt[c-'A']++;
	rep(i,6) printf("%d%c",cnt[i],i<5?' ':'\n');

	return 0;
}
