#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int main(){
	int a,b,c; cin>>a>>b>>c;
	cout<<(c%gcd(a,b)==0?"YES":"NO")<<endl;
	return 0;
}
