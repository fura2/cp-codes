#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	double ans=0;
	rep(_,n){
		double a;
		string s; cin>>a>>s;
		if(s=="JPY") ans+=a;
		else         ans+=a*380'000;
	}
	cout<<ans<<endl;

	return 0;
}
