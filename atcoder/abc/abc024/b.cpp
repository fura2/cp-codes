#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct interval{
	T l,r;
	interval():l(T{}),r(T{}){}
	interval(const T& l,const T& r):l(l),r(r){}
	bool operator<(const interval& I)const{ return make_tuple(l,r)<make_tuple(I.l,I.r); }
};

template<class T>
vector<interval<T>> interval_union(vector<interval<T>> I){
	sort(I.begin(),I.end(),[](const interval<T>& a,const interval<T>& b){ return a.l<b.l; });

	int n=I.size();
	if(n==0) return {};

	vector<interval<T>> res;
	T l=I[0].l,r=I[0].r;
	for(int i=1;i<=n;i++){
		if(i==n || r<I[i].l){
			res.emplace_back(l,r);
			if(i<n){
				l=I[i].l;
				r=I[i].r;
			}
		}
		else if(r<I[i].r){
			r=I[i].r;
		}
	}
	return res;
}

int main(){
	int n,T; scanf("%d%d",&n,&T);

	vector<interval<int>> I(n);
	rep(i,n) scanf("%d",&I[i].l), I[i].r=I[i].l+T;

	int ans=0;
	for(auto J:interval_union(I)) ans+=J.r-J.l;
	printf("%d\n",ans);

	return 0;
}
