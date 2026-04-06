#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

// #{ (x,y) | l <= x,y < r and gcd(x,y) = 1 }
lint f(int l,int r){
	if(l>=r) return 0;

	vector<lint> a(r);
	for(int g=r-1;g>=1;g--){
		lint k=(r-1)/g-(l-1)/g;
		a[g]=k*k;
		for(int e=2*g;e<r;e+=g){
			a[g]-=a[e];
		}
	}
	return a[1];
}

int main(){
	int l,r; scanf("%d%d",&l,&r); r++;

	lint ans=0;
	for(int g=2;g<r;g++){
		ans+=f(max((l+g-1)/g,2),(r+g-1)/g);
	}
	printf("%lld\n",ans);

	return 0;
}
