#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class G>
class Fenwick_tree_dual{
	vector<G> a;
public:
	Fenwick_tree_dual(int n):a(n){}
	void add(int l,int r,G val){
		if(l==0){
			for(;r>0;r-=r&-r) a[r-1]+=val;
			return;
		}
		add(0,r,val);
		add(0,l,-val);
	}
	G sum(int i)const{
		G res{};
		for(i++;i<=a.size();i+=i&-i) res+=a[i-1];
		return res;
	}
};

int main(){
	int n; scanf("%d",&n);

	Fenwick_tree_dual<int> A(n),B(n);
	rep(i,n){
		A.add(i,i+1,i+1);
		B.add(i,i+1,n-i);
	}
	rep(i,n){
		int p; scanf("%d",&p); p--;
		A.add(p,n,i);
		B.add(p+1,n,-i);
	}

	int a_min=1e9,b_min=1e9;
	rep(i,n){
		a_min=min(a_min,A.sum(i));
		b_min=min(b_min,B.sum(i));
	}
	A.add(0,n,1-a_min);
	B.add(0,n,1-b_min);

	rep(i,n) printf("%d%c",A.sum(i),i<n-1?' ':'\n');
	rep(i,n) printf("%d%c",B.sum(i),i<n-1?' ':'\n');

	return 0;
}
