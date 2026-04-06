#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }

void solve(){
	lint a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);

	if(a<b || d<b){
		puts("No");
		return;
	}

	if(c>=b){
		puts("Yes");
		return;
	}

	lint m=(a-c+b-1)/b; // m = min{ m | a - m*b <= c }
	if(a-m*b<0){
		puts("No");
		return;
	}

	lint g=gcd(d-b,b);
	lint x=(b-(a-m*b)-1)/g; // x = max{ x | a - m*b + x*g < b }
	puts(a-m*b+x*g>c?"No":"Yes");
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
