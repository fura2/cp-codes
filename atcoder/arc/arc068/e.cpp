#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class G>
class Fenwick_tree_dual{
	vector<G> a;
public:
	Fenwick_tree_dual(int n):a(n){}
	void add(int l,int r,G val){
		if(l==0){
			for(;r>0;r-=r&-r) a[r-1]+=val;
			return;
		}
		add(0,r,val);
		add(0,l,-val);
	}
	G sum(int i){
		G res{};
		for(i++;i<=a.size();i+=i&-i) res+=a[i-1];
		return res;
	}
};

struct interval{
	int l,r;
	bool operator<(const interval& I)const{ return r-l<I.r-I.l; }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<interval> I(n);
	rep(i,n) scanf("%d%d",&I[i].l,&I[i].r), I[i].r++;

	sort(I.begin(),I.end());

	int idx=0;
	Fenwick_tree_dual<int> F(m+1);
	for(int d=1;d<=m;d++){
		while(idx<n && I[idx].r-I[idx].l<=d){
			F.add(I[idx].l,I[idx].r,1);
			idx++;
		}

		int ans=n-idx;
		for(int x=d;x<=m;x+=d) ans+=F.sum(x);
		printf("%d\n",ans);
	}

	return 0;
}
