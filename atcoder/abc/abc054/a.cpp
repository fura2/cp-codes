#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; cin>>a>>b;
	auto f=[](int x){ return x==1?x+13:x; };
	cout<<(f(a)==f(b)?"Draw":f(a)>f(b)?"Alice":"Bob")<<'\n';
	return 0;
}
