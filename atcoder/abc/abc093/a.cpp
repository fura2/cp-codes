#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	sort(s.begin(),s.end());
	cout<<(s=="abc"?"Yes":"No")<<endl;

	return 0;
}
