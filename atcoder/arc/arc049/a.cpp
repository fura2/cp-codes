#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int a,b,c,d; cin>>s>>a>>b>>c>>d;
	s=s.substr(0,d)+"\""+s.substr(d);
	s=s.substr(0,c)+"\""+s.substr(c);
	s=s.substr(0,b)+"\""+s.substr(b);
	s=s.substr(0,a)+"\""+s.substr(a);
	cout<<s<<'\n';
	return 0;
}
