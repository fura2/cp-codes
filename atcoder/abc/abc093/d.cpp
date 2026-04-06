#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint solve(){
	lint a,b; cin>>a>>b;
	if(a<b) swap(a,b);
	if(a==b) return (a-1)+(b-1);

	lint m=sqrt(a*b)+1;
	while(m*m>a*b) m--;

	lint l=m,r=m;
	while((l+1)*r<a*b) l++;

	lint res=0;
	res+=b-1; // (a+1, b-1), (a+2, b-2), ..., (a+b-1, 1)
	res+=r-b; // (*, b+1), (*, b+2), ..., (l, r)
	res+=l-1; // (l-1, r+1), (l-2, r+2), ..., (1, l+r-1)
	if(m*m==a*b) res--;

	return res;
}

int main(){
	int q; cin>>q;
	rep(_,q) cout<<solve()<<endl;
	return 0;
}
