#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,a,b,c,d; cin>>n>>a>>b>>c>>d;
	n--;
	rep(i,n+1) if(i*c-(n-i)*d<=b-a && b-a<=i*d-(n-i)*c) return puts("YES"),0;
	puts("NO");
	return 0;
}
