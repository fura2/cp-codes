#include <algorithm>
#include <iostream>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k;
	string s;
	cin>>n>>k>>s;

	int ans=2*k;
	rep(i,n-1) if(s[i]==s[i+1]) ans++;
	cout<<min(ans,n-1)<<endl;

	return 0;
}
