#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	cout<<(a==c||a==d||b==c||b==d?"YES":"NO")<<'\n';
	return 0;
}
