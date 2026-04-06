#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

const int INF=1<<29;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=INF;
	rep(S,1<<n) if(S!=0) {
		lint x=0;
		rep(i,n) if(S>>i&1) x=10*x+(s[i]-'0');
		if(x%3==0) ans=min(ans,n-popcount(S));
	}
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
