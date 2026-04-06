#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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

	vector<interval<T>> Res;
	T l=I[0].l,r=I[0].r;
	for(int i=1;i<=n;i++){
		if(i==n || r<I[i].l){
			Res.emplace_back(l,r);
			if(i<n){
				l=I[i].l;
				r=I[i].r;
			}
		}
		else if(r<I[i].r){
			r=I[i].r;
		}
	}
	return Res;
}

lint all_or(lint a,lint b){
	for(int i=60;i>=0;i--) if((a>>i)<(b>>i)) return ((b>>i)<<i)|((1LL<<i)-1);
	return b;
}

int main(){
	lint a,b; cin>>a>>b;

	lint x=b;
	for(int i=60;i>=0;i--) if((a>>i)<(b>>i)) {
		x=(b>>i)<<i;
		break;
	}
	lint y=all_or(x,b);
	lint z=all_or(a,b);

	lint ans=0;
	for(auto J:interval_union(vector<interval<lint>>{{a,y+1},{a|x,z+1}})) ans+=J.r-J.l;
	printf("%lld\n",ans);

	return 0;
}
