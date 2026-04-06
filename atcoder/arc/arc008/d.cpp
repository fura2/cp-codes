#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class M>
class segment_tree{
	int sz;
	vector<M> seg;
public:
	segment_tree(){}
	segment_tree(int n){ build(n); }
	template<class T>
	segment_tree(const vector<T>& a){ build(a); }
	void build(int n){
		for(sz=1;sz<n;sz<<=1);
		seg.assign(2*sz,M());
	}
	template<class T>
	void build(const vector<T>& a){
		int n=a.size();
		build(n);
		rep(i,n) seg[sz+i]=a[i];
		for(int i=sz-1;i>0;i--){
			seg[i]=seg[2*i]*seg[2*i+1];
		}
	}
	const M& operator[](int i)const{
		return seg[sz+i];
	}
	void update(int i,const M& x){
		i+=sz;
		seg[i]=x;
		for(i>>=1;i>0;i>>=1) seg[i]=seg[2*i]*seg[2*i+1];
	}
	M get(int l,int r)const{
		M lcum=M(),rcum=M();
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*seg[a++];
			if(b&1) rcum=seg[--b]*rcum;
		}
		return lcum*rcum;
	}
};

template<class T>
class linear_function_monoid{
	T a,b;
public:
	linear_function_monoid():a(1),b(){}
	linear_function_monoid(const T& a,const T& b):a(a),b(b){}
	linear_function_monoid operator*(const linear_function_monoid& x)const{
		return {x.a*a,x.a*b+x.b};
	}
	pair<T&,T&> get(){ return {a,b}; }
	pair<const T&,const T&> get()const{ return {a,b}; }
	T eval(const T& x)const{ return a*x+b; }
};

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> p(q);
	vector<double> a(q),b(q);
	rep(i,q) scanf("%lld%lf%lf",&p[i],&a[i],&b[i]), p[i]--;

	auto X=p;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	rep(i,q) p[i]=lower_bound(X.begin(),X.end(),p[i])-X.begin();
	n=X.size();

	double mn=1,mx=1;
	segment_tree<linear_function_monoid<double>> S(n);
	rep(i,q){
		S.update(p[i],{a[i],b[i]});
		double tmp=S.get(0,n).eval(1);
		mn=min(mn,tmp);
		mx=max(mx,tmp);
	}
	printf("%.9f\n%.9f\n",mn,mx);

	return 0;
}
