#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; cin>>a>>b>>c;
	cout<<max({a,b,c})-min({a,b,c})<<endl;

	return 0;
}
