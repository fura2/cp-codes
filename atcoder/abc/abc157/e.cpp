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
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};

int main(){
	int n;
	string s; cin>>n>>s;

	vector<Fenwick_tree<int>> F(26,Fenwick_tree<int>(n));
	rep(i,n) F[s[i]-'a'].add(i,1);

	int q; scanf("%d",&q);
	rep(_,q){
		int type,a; scanf("%d%d",&type,&a); a--;
		if(type==1){
			char c; scanf(" %c",&c);
			char pre=s[a];
			s[a]=c;
			F[pre-'a'].add(a,-1);
			F[c-'a'].add(a,1);
		}
		else{
			int b; scanf("%d",&b);
			int ans=0;
			rep(c,26) if(F[c].sum(a,b)>0) ans++;
			printf("%d\n",ans);
		}
	}

	return 0;
}
