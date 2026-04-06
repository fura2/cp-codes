#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
class Fenwick_tree{
	vector<T> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,T val){
		for(;i<a.size();i|=i+1) a[i]+=val;
	}
	T sum(int l,int r){
		if(l==0){
			T res{};
			for(r--;r>=0;r=(r&(r+1))-1) res+=a[r];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
};

int n,a[100000];

// number of pairs (l, r) such that median of a[l..r) >= x
lint solve(int x){
	lint res=0;
	int sum=0;
	Fenwick_tree<int> F(2*n+1);
	F.add(n,1);
	rep(i,n){
		sum+=(a[i]>=x?1:-1);
		res+=F.sum(0,n+sum+1);
		F.add(n+sum,1);
	}
	return res;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i);

	lint m=n*(n+1LL)/2;

	int lo=0,hi=1e9+1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if((m+1)/2<=solve(mi)) lo=mi;
		else                   hi=mi;
	}
	printf("%d\n",lo);

	return 0;
}
