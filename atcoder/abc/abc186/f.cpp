#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(){}
	Fenwick_tree(int n){ build(n); }
	Fenwick_tree(const vector<G>& a){ build(a); }
	void build(int n){
		a.assign(n,G{});
	}
	void build(const vector<G>& a){
		this->a=a;
		for(int i=1;i<a.size();i++) if(i+(i&-i)-1<a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];
	}
	void add(int i,const G& val){
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

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]), x[i]--, y[i]--;

	vector f(h,vector(1,w));
	rep(i,n) f[x[i]].emplace_back(y[i]);
	rep(i,h) sort(f[i].begin(),f[i].end());

	int x_max=h,y_max=w;
	rep(i,n){
		if(y[i]==0) x_max=min(x_max,x[i]);
		if(x[i]==0) y_max=min(y_max,y[i]);
	}

	Fenwick_tree<int> F(w+1); // 1 行目から降ろしてこれる列は 1, それ以外は 0
	rep(j,y_max) F.add(j,1);

	lint ans=y_max;
	for(int i=1;i<h;i++){
		for(int j:f[i]){
			if(F.sum(j,j+1)==1) F.add(j,-1);
		}
		if(i<x_max){
			ans+=f[i][0]+F.sum(f[i][0],w);
		}
		else{
			ans+=F.sum(0,w);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
