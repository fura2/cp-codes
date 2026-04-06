#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint w; scanf("%d%lld",&n,&w);

	vector<lint> cum(200001);
	rep(i,n){
		int l,r;
		lint a; scanf("%d%d%lld",&l,&r,&a);
		cum[l]+=a;
		cum[r]-=a;
	}
	rep(x,200000) cum[x+1]+=cum[x];

	rep(x,200001) if(cum[x]>w) {
		puts("No");
		return 0;
	}
	puts("Yes");

	return 0;
}
