#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,G val){
		for(;i<a.size();i|=i+1) a[i]+=val;
	}
	G sum(int l,int r){
		if(l==0){
			G res{};
			for(r--;r>=0;r=(r&(r+1))-1) res+=a[r];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
};

int main(){
	int n,k; cin>>n>>k;
	Fenwick_tree<lint> F(n);
	rep(i,n){
		int a; cin>>a;
		F.add(i,a);
	}

	lint ans=0;
	rep(i,n-k+1) ans+=F.sum(i,i+k);
	cout<<ans<<endl;

	return 0;
}
