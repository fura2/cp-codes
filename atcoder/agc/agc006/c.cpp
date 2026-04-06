#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
T pow(T f,long long k){
	T res;
	for(;k>0;k>>=1){
		if(k&1) res=res*f;
		f=f*f;
	}
	return res;
}

class permutation_monoid{
	vector<int> p;
public:
	permutation_monoid(){}
	permutation_monoid(const vector<int>& p):p(p){}
	permutation_monoid operator*(const permutation_monoid& a)const{
		int n=p.size(),m=a.p.size();
		int k=max(n,m);
		vector<int> res(k);
		rep(i,k){
			int x=(i<m?a.p[i]:i);
			res[i]=(x<n?p[x]:x);
		}
		return res;
	}
	int operator[](int i)const{ return i<p.size()?p[i]:i; }
};

int main(){
	int n; scanf("%d",&n);
	vector<lint> x(n);
	rep(i,n) scanf("%lld",&x[i]);
	int m;
	lint k; scanf("%d%lld",&m,&k);
	vector<int> a(m);
	rep(i,m) scanf("%d",&a[i]), a[i]--;

	vector<lint> dif(n-1);
	rep(i,n-1) dif[i]=x[i+1]-x[i];

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	rep(i,m) swap(p[a[i]-1],p[a[i]]);

	auto q=pow(permutation_monoid(p),k);

	vector<lint> ans(n);
	ans[0]=x[0];
	rep(i,n-1) ans[i+1]=ans[i]+x[q[i]+1]-x[q[i]];
	rep(i,n) printf("%lld\n",ans[i]);

	return 0;
}
