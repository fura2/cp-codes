#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;

	sort(s.begin(),s.end());
	sort(t.begin(),t.end(),greater<char>());

	cout<<(s<t?"Yes":"No")<<endl;

	return 0;
}
