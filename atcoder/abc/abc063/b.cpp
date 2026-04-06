#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	sort(s.begin(),s.end());
	cout<<(unique(s.begin(),s.end())==s.end()?"yes":"no")<<endl;
	return 0;
}
