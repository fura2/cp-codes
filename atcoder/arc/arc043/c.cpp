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

class permutation{
	vector<int> f;
public:
	permutation(){}
	permutation(int n){
		f.resize(n);
		rep(i,n) f[i]=i;
	}
	permutation(const vector<int>& p):f(p){}

	permutation operator*(const permutation& p)const{
		int n=f.size();
		permutation res(n);
		rep(i,n) res.f[i]=f[p[i]];
		return res;
	}
	int operator[](int i)const{ return f[i]; }

	int size()const{ return f.size(); }

	friend permutation inverse(const permutation& p){
		int n=p.f.size();
		permutation res(n);
		rep(i,n) res.f[p.f[i]]=i;
		return res;
	}
};

long long inversion_number(const permutation& p){
	int n=p.size();
	long long res=0;
	Fenwick_tree<int> F(n);
	rep(i,n){ res+=F.sum(p[i]+1,n); F.add(p[i],1); }
	return res;
}

int main(){
	int n; scanf("%d",&n);
	permutation a,b;
	{
		vector<int> in(n);
		rep(i,n) scanf("%d",&in[i]), in[i]--;
		a=in;
		rep(i,n) scanf("%d",&in[i]), in[i]--;
		b=in;
	}
	a=inverse(b)*a;

	lint total=inversion_number(a);

	if(total%2==1) return puts("-1"),0;

	lint cnt=0;
	int i0=-1;
	auto pos=inverse(a);
	Fenwick_tree<int> Used(n);
	rep(i,n){
		int d=pos[i]-Used.sum(0,pos[i]);
		if(cnt+d>=total/2){ i0=i; break; }
		cnt+=d;
		Used.add(pos[i],1);
	}

	assert(i0!=-1);

	permutation ans;
	{
		vector<int> p(n);
		rep(j,i0) p[j]=j;
		int idx=i0;
		rep(j,n){
			if(a[j]>=i0) p[idx++]=a[j];
			if(a[j]==i0){
				rep(k,total/2-cnt){
					swap(p[idx-k-1],p[idx-k-2]);
				}
			}
		}
		assert(idx==n);
		ans=b*permutation(p);
	}
	rep(i,n) printf("%d%c",ans[i]+1,i<n-1?' ':'\n');

	return 0;
}
