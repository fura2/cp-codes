#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

using namespace std;

ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }

ll lcm(ll a,ll b){ return a/gcd(a,b)*b; }

ll solve(ll a,ll c,ll d){
	return a-a/c-a/d+a/lcm(c,d);
}

int main(){
	ll a,b,c,d; cin>>a>>b>>c>>d;
	cout<<solve(b,c,d)-solve(a-1,c,d)<<endl;
	return 0;
}
