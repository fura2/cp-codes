#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
class sparse_table{
	vector<vector<T>> st;
	vector<int> h;
public:
	sparse_table(const vector<T>& a){
		int n=a.size();
		h.assign(n+1,0);
		for(int i=2;i<=n;i++) h[i]=h[i>>1]+1;
		st.resize(h[n]+1);
		st[0]=a;
		for(int i=1;i<h[n]+1;i++){
			st[i].resize(n-(1<<i)+1);
			rep(j,n-(1<<i)+1) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	T query(int l,int r)const{
		int i=h[r-l];
		return min(st[i][l],st[i][r-(1<<i)]);
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n+1);

	vector<pair<int,int>> I(m);
	rep(i,m){
		scanf("%d%d",&I[i].first,&I[i].second); I[i].first--;
		a[I[i].first]++;
		a[I[i].second]--;
	}

	rep(i,n) a[i+1]+=a[i];

	sparse_table<int> ST(a);

	vector<int> ans;
	rep(i,m) if(ST.query(I[i].first,I[i].second)>1) ans.emplace_back(i);
	printf("%lu\n",ans.size());
	for(int i:ans) printf("%d\n",i+1);

	return 0;
}
