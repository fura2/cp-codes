// O(N*2^N) solution

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class best2_monoid{
public:
	int v1,v2;
	best2_monoid(int v1=0,int v2=0):v1(v1),v2(v2){}
	best2_monoid operator*(best2_monoid x)const{
		int w1=v1,w2=v2;
		for(int w3:{x.v1,x.v2}){
			if(w3>w1){
				w2=w1;
				w1=w3;
			}
			else if(w3>w2){
				w2=w3;
			}
		}
		return {w1,w2};
	}
};

template<class M>
vector<M> zeta_subset(vector<M> f){
	int n=log2(f.size());
	rep(i,n) rep(S,1<<n) if(~S>>i&1) f[S|1<<i]=f[S|1<<i]*f[S];
	return f;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(1<<n);
	rep(S,1<<n) scanf("%d",&a[S]);

	vector<best2_monoid> f(1<<n);
	rep(S,1<<n) f[S].v1=a[S];

	f=zeta_subset(f);

	int ans=0;
	for(int S=1;S<(1<<n);S++){
		ans=max(ans,f[S].v1+f[S].v2);
		printf("%d\n",ans);
	}

	return 0;
}
