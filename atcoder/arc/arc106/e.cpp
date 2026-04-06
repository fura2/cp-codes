#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<int> zeta_subset(vector<int> f){
	int n=log2(f.size());
	rep(i,n) rep(S,1<<n) if(~S>>i&1) f[S|1<<i]+=f[S];
	return f;
}

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> C(2*n*k); // C[t] = (t 日目に働いている人の集合)
	rep(t,C.size()){
		rep(i,n) if(t%(2*a[i])<a[i]) C[t]|=1<<i;
	}

	int lo=n*k-1,hi=2*n*k;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		vector<int> f(1<<n);
		rep(t,mi) f[C[t]]++;
		f=zeta_subset(f);

		bool ok=true;
		rep(S,1<<n) if(mi-f[((1<<n)-1)&~S]<k*popcount(S)) ok=false;

		if(ok) hi=mi;
		else   lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
