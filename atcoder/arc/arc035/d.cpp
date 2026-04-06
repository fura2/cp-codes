#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,G val){
		for(i++;i<=a.size();i+=i&-i) a[i-1]+=val;
	}
	G sum(int l,int r)const{
		if(l==0){
			G res{};
			for(;r>0;r-=r&-r) res+=a[r-1];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
};

int main(){
	vector<double> logfact(2e6+1);
	logfact[0]=0;
	rep(i,2e6) logfact[i+1]=logfact[i]+log(i+1);

	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	Fenwick_tree<double> F(n-1);
	rep(i,n-1){
		int dx=x[i+1]-x[i];
		int dy=y[i+1]-y[i];
		F.add(i,logfact[dx+dy]-logfact[dx]-logfact[dy]);
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int t; scanf("%d",&t);
		if(t==1){
			int k,a,b,dx,dy; scanf("%d%d%d",&k,&a,&b); k--;
			x[k]=a;
			y[k]=b;
			if(k>0){
				dx=x[k]-x[k-1];
				dy=y[k]-y[k-1];
				F.add(k-1,-F.sum(k-1,k));
				F.add(k-1,logfact[dx+dy]-logfact[dx]-logfact[dy]);
			}
			if(k<n-1){
				dx=x[k+1]-x[k];
				dy=y[k+1]-y[k];
				F.add(k,-F.sum(k,k+1));
				F.add(k,logfact[dx+dy]-logfact[dx]-logfact[dy]);
			}
		}
		else{
			int l1,r1,l2,r2; scanf("%d%d%d%d",&l1,&r1,&l2,&r2); l1--; r1--; l2--; r2--;
			puts(F.sum(l1,r1)>F.sum(l2,r2)?"FIRST":"SECOND");
		}
	}

	return 0;
}
