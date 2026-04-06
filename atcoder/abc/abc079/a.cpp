#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	cout<<(s[1]==s[2]&&(s[0]==s[1]||s[3]==s[1])?"Yes":"No")<<endl;

	return 0;
}
