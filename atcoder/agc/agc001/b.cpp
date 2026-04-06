#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,x; cin>>n>>x;

	lint ans=x;
	lint a=x,b=n,c=n-x,d=n-x;
	while(1){
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);

		if(b==d){ ans+=b; break; }

		if(b>d){ lint m=b/d-(b%d==0?1:0); ans+=m*d; b-=m*d; }
		else   { lint m=d/b-(d%b==0?1:0); ans+=m*b; d-=m*b; }
	}
	cout<<ans<<endl;

	return 0;
}
