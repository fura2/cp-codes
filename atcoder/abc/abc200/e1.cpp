#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint f(lint r,lint n){ // #{ (b, c) | 0 <= b, c <= n and b + c = r }
	if(r<0 || 2*n<r) return 0;
	if(r<=n) return r+1;
	else     return 2*n-r+1;
}

int main(){
	lint n,k; scanf("%lld%lld",&n,&k); n--; k--;

	lint r; // r = a + b + c
	for(r=0;r<=3*n;r++){
		lint m;
		if(r<=n){
			m=(r+1)*(r+2)/2;
		}
		else if(r<2*n){
			m=(r+1)*(r+2)/2-3*(r-n)*(r-n+1)/2;
		}
		else{
			m=(3*n-r+1)*(3*n-r+2)/2;
		}
		if(k<m) break;
		k-=m;
	}

	lint a;
	for(a=0;a<=r;a++){
		lint m=f(r-a,n);
		if(k<m) break;
		k-=m;
	}

	lint b,c;
	for(b=0;b<=r-a;b++){
		c=r-a-b;
		if(0<=c && c<=n){
			if(k==0) break;
			k--;
		}
	}

	printf("%lld %lld %lld\n",a+1,b+1,c+1);

	return 0;
}
