#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct interval{
	T l,r;
	interval(){}
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
	lint a,c; cin>>a>>c;

	lint l1,r1,l2,r2;
	l1=a-c/2;
	if(c==1) r1=a;
	else     r1=a+(c-2)/2;
	l2=-a-(c-1)/2;
	r2=-a+(c-1)/2;

	vector<interval<lint>> J;
	J.emplace_back(l1,r1+1);
	J.emplace_back(l2,r2+1);

	lint ans=0;
	for(auto J:interval_union(J)) ans+=J.r-J.l;
	printf("%lld\n",ans);

	return 0;
}
