#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int sum=0;
	for(char c:s) sum+=c-'0';
	cout<<max<int>(sum,(s[0]-'1')+9*(s.length()-1))<<'\n';

	return 0;
}
