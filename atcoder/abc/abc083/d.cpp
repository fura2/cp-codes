#include <iostream>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int i;
	for(i=(n+1)/2; i<n && s[i]==s[n-i-1] && s[i]==s[n/2]; i++);
	cout<<i<<endl;

	return 0;
}
