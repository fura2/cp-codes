#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
};

int main(){
	int q; scanf("%d",&q);

	Fenwick_tree<int> F(2e5+1);
	rep(_,q){
		int t,x; scanf("%d%d",&t,&x);
		if(t==1){
			F.add(x,1);
		}
		else{
			int pos=F.lower_bound(x);
			printf("%d\n",pos);
			F.add(pos,-1);
		}
	}

	return 0;
}
