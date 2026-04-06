#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; cin>>a>>b>>c;
	cout<<max({10*a+b+c,10*b+c+a,10*c+a+b})<<endl;

	return 0;
}
