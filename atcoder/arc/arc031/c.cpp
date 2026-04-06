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
	int n; cin>>n;
	vector<int> a(n),p(n);
	rep(i,n){
		cin>>a[i]; a[i]--;
		p[a[i]]=i;
	}

	Fenwick_tree<int> F(n);
	rep(i,n) F.add(i,1);

	lint ans=0;
	rep(i,n){
		ans+=min(F.sum(0,p[i]),F.sum(p[i]+1,n));
		F.add(p[i],-1);
	}
	cout<<ans<<endl;

	return 0;
}
