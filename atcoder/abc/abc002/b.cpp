#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	for(char c:s) if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u') cout<<c;
	cout<<endl;

	return 0;
}
