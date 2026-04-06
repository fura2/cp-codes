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
	int lower_bound(G val)const{
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n);
	rep(i,n) scanf("%d",&x[i]);
	int L; scanf("%d",&L);

	Fenwick_tree<int> F(n);
	F.add(0,x[0]);
	rep(i,n-1) F.add(i+1,x[i+1]-x[i]);

	vector<int> next(n,n);
	for(int i=n-2;i>=0;i--){
		next[i]=F.upper_bound(x[i]+L)-1;
	}

	vector<vector<int>> dbl(20,vector<int>(n+1,n)); // doubling
	rep(i,n) dbl[0][i]=next[i];
	rep(dep,19) rep(i,n) dbl[dep+1][i]=dbl[dep][dbl[dep][i]];

	int q; scanf("%d",&q);
	rep(_,q){
		int a,b; scanf("%d%d",&a,&b); a--; b--;
		if(a>b) swap(a,b);
		int ans=0;
		for(int dep=19;dep>=0;dep--){
			if(dbl[dep][a]<=b){
				a=dbl[dep][a];
				ans+=1<<dep;
			}
		}
		if(a<b) ans++;
		printf("%d\n",ans);
	}

	return 0;
}
