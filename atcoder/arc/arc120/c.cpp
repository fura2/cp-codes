#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n=0){ build(n); }
	Fenwick_tree(const vector<G>& a){ build(a); }
	void build(int n){
		a.assign(n,G{});
	}
	void build(const vector<G>& a){
		this->a=a;
		for(int i=1;i<=a.size();i++) if(i+(i&-i)<=a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];
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
		if(!(G{}<val)) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && !(val<a[x+k-1])) val-=a[x+k-1], x+=k;
		return x;
	}
};

template<class T>
long long inversion_number(const vector<T>& a){
	auto X=a;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	long long res=0;
	Fenwick_tree<int> F(X.size());
	rep(i,a.size()){
		int x=lower_bound(X.begin(),X.end(),a[i])-X.begin();
		res+=F.sum(x+1,X.size());
		F.add(x,1);
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	map<int,vector<int>> L,R;
	rep(i,n){
		L[a[i]+i].emplace_back(i);
		R[b[i]+i].emplace_back(i);
	}

	if(L.size()!=R.size()){
		puts("-1");
		return 0;
	}

	vector<int> seq(n);
	for(auto [x,v1]:L){
		if(R.count(x)==0 || R[x].size()!=v1.size()){
			puts("-1");
			return 0;
		}
		auto& v2=R[x];
		rep(i,v1.size()) seq[v1[i]]=v2[i];
	}
	printf("%lld\n",inversion_number(seq));

	return 0;
}
