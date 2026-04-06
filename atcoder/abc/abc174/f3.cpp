// segment tree (abstract version)

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
		M lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*seg[a++];
			if(b&1) rcum=seg[--b]*rcum;
		}
		return lcum*rcum;
	}
	template<class N,class F>
	N query(int l,int r,const F& f){
		N lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*f(seg[a++]);
			if(b&1) rcum=f(seg[--b])*rcum;
		}
		return lcum*rcum;
	}
};

template<class T>
class sequence_monoid{
	vector<T> a;
public:
	sequence_monoid(){}
	sequence_monoid(const T& val):a(1,val){}
	sequence_monoid(const vector<T>& x):a(x){
		sort(a.begin(),a.end());
	}
	sequence_monoid operator*(const sequence_monoid& x)const{
		vector<T> res;
		merge(a.begin(),a.end(),x.a.begin(),x.a.end(),back_inserter(res));
		return res;
	}
	int lower_bound(const T& val)const{
		return std::lower_bound(a.begin(),a.end(),val)-a.begin();
	}
};

template<class T>
class add_monoid{
	T a;
public:
	add_monoid():a(){}
	add_monoid(const T& val):a(val){}
	add_monoid operator*(const add_monoid& x)const{
		return a+x.a;
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	vector<int> x(n),pre(n,-1);
	rep(i,n){
		x[i]=pre[a[i]];
		pre[a[i]]=i;
	}

	segment_tree<sequence_monoid<int>> S(x);
	rep(_,q){
		int l,r; scanf("%d%d",&l,&r); l--;
		auto ans=S.query<add_monoid<int>>(l,r,[&](const sequence_monoid<int>& x)->add_monoid<int>{
			return x.lower_bound(l);
		});
		printf("%d\n",ans.get());
	}

	return 0;
}
