#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class F2{
	bool x;
public:
	F2():x(false){}
	F2(long long n){ assert(n==0||n==1); x=(n==1); }
	F2& operator+=(const F2& a){ x=(x!=a.x); return *this; }
	F2& operator-=(const F2& a){ return (*this)+=a; }
	F2& operator*=(const F2& a){ x=(x&&a.x); return *this; }
	F2& operator/=(const F2& a){ assert(a.x); return *this; }
	F2 operator+(const F2& a)const{ return F2(*this)+=a; }
	F2 operator-(const F2& a)const{ return F2(*this)-=a; }
	F2 operator*(const F2& a)const{ return F2(*this)*=a; }
	F2 operator/(const F2& a)const{ return F2(*this)/=a; }
	bool operator==(const F2& a)const{ return x==a.x; }
	bool operator!=(const F2& a)const{ return !((*this)==a); }
	int to_int()const{ return x; }
};

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

vector<F2> cnt;
vector<bool> vis;
vector<int> ans;

weighted_graph<int> G;

void dfs(int i){
	vis[i]=true;
	for(const auto& e:G[i]) if(!vis[e.to]) {
		dfs(e.to);
		if(cnt[e.to]==1){ // use this edge
			cnt[i]+=1;
			cnt[e.to]+=1;
			ans.emplace_back(e.wt);
		}
	}
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(n),l(m),r(m);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);
	rep(j,m) scanf("%d%d",&l[j],&r[j]);

	{
		vector<pair<int,int>> p(n);
		rep(i,n) p[i]={a[i],b[i]};
		sort(p.begin(),p.end());
		rep(i,n) tie(a[i],b[i])=p[i];
	}

	// 差分をとる
	cnt.resize(n+1);
	rep(i,n) cnt[i]=b[i];
	for(int i=n;i>0;i--) cnt[i]-=cnt[i-1];

	G.resize(n+1);
	rep(j,m){
		int il=lower_bound(a.begin(),a.end(),l[j])-a.begin();
		int ir=upper_bound(a.begin(),a.end(),r[j])-a.begin();
		if(il<ir){
			G[il].emplace_back(ir,j);
			G[ir].emplace_back(il,j);
		}
	}

	vis.resize(n+1);
	rep(i,n+1) if(!vis[i]) dfs(i);

	if(count(cnt.begin(),cnt.end(),0)<n+1){
		puts("-1");
	}
	else{
		sort(ans.begin(),ans.end());
		printf("%lu\n",ans.size());
		rep(i,ans.size()) printf("%d%c",ans[i]+1,i+1<ans.size()?' ':'\n');
	}

	return 0;
}
