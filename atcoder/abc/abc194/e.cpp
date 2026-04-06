#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(){}
	Fenwick_tree(int n){ build(n); }
	Fenwick_tree(const vector<G>& a){ build(a); }
	void build(int n){
		a.assign(n,G{});
	}
	void build(const vector<G>& a){
		this->a=a;
		for(int i=1;i<a.size();i++) if(i+(i&-i)-1<a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];
	}
	void add(int i,const G& val){
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
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> cnt(n);
	rep(i,m) cnt[a[i]]++;

	Fenwick_tree<int> F(vector<int>(n,1));
	rep(x,n) if(cnt[x]>0) F.add(x,-1);

	int ans=n;
	rep(i,n-m+1){
		ans=min(ans,F.lower_bound(1));
		cnt[a[i]]--;
		if(cnt[a[i]]==0) F.add(a[i],1);
		if(i+m<n){
			if(cnt[a[i+m]]==0) F.add(a[i+m],-1);
			cnt[a[i+m]]++;
		}
	}
	printf("%d\n",ans);

	return 0;
}
