#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
class Fenwick_tree_dual{
	vector<T> a;
public:
	Fenwick_tree_dual(int n):a(n){}
	void add(int l,int r,T val){
		if(l==0){
			for(r--;r>=0;r=(r&(r+1))-1) a[r]+=val;
			return;
		}
		add(0,r,val);
		add(0,l,-val);
	}
	T sum(int i){
		T res{};
		for(;i<a.size();i|=i+1) res+=a[i];
		return res;
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	Fenwick_tree_dual<lint> F1(m),F2(m);
	rep(i,n-1){
		int l=a[i],r=a[i+1];
		if(a[i]<a[i+1]){
			if(a[i]+2<=a[i+1]){
				F1.add(a[i]+2,a[i+1]+1,1);
				if(a[i+1]<m-1) F1.add(a[i+1]+1,a[i+1]+2,-(a[i+1]-a[i]-1));
			}
		}
		else{
			if(a[i]+2<=m){
				F1.add(a[i]+2,m,1);
			}
			if(a[i+1]>=0){
				if(a[i]<m-1){
					F1.add(0,a[i+1]+1,1);
					F1.add(a[i+1]+1,a[i+1]+2,-(a[i+1]+1));
					F2.add(0,a[i+1]+1,m-a[i]-2);
				}
				else{
					F1.add(1,a[i+1]+1,1);
					F1.add(a[i+1]+1,a[i+1]+2,-a[i+1]);
				}
			}
		}
	}
	rep(i,m-1) F1.add(i+1,i+2,F1.sum(i));

	lint mx=0;
	rep(i,m) mx=max(mx,F1.sum(i)+F2.sum(i));

	lint ans=-mx;
	rep(i,n-1) ans+=(a[i+1]-a[i]+m)%m;
	cout<<ans<<endl;

	return 0;
}
