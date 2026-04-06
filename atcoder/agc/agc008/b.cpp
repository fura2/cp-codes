#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,G val){
		for(i++;i<=a.size();i+=i&-i) a[i-1]+=val;
	}
	G sum(int l,int r)const{
		if(l==0){
			G res{};
			for(;r>0;r-=r&-r) res+=a[r-1];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
	int lower_bound(G val)const{
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};

const long long INF=1LL<<61;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	Fenwick_tree<lint> F_plus(n),F_minus(n);
	rep(i,n){
		int a; scanf("%d",&a);
		if(a>0) F_plus .add(i, a);
		if(a<0) F_minus.add(i,-a);
	}

	lint ans=-INF;
	rep(i,n-k+1){
		lint mid=F_plus.sum(i,i+k)-F_minus.sum(i,i+k);
		ans=max(ans,F_plus.sum(0,i)+max(mid,0LL)+F_plus.sum(i+k,n));
	}
	printf("%lld\n",ans);

	return 0;
}
