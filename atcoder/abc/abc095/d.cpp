#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
class sparse_table{
	vector<vector<T>> st;
	vector<int> h;
public:
	sparse_table(const vector<T> &a){
		int n=a.size();
		h.assign(n+1,0);
		for(int i=2;i<=n;i++) h[i]=h[i>>1]+1;
		st.resize(h[n]+1);
		st[0]=a;
		for(int i=1;i<h[n]+1;i++){
			st[i].resize(n-(1<<i)+1);
			rep(j,n-(1<<i)+1) st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
	T query(int l,int r)const{
		int i=h[r-l];
		return max(st[i][l],st[i][r-(1<<i)]);
	}
};

int main(){
	int n;
	lint L; scanf("%d%lld",&n,&L);
	vector<lint> x(n),v(n);
	rep(i,n) scanf("%lld%lld",&x[i],&v[i]);

	vector<lint> score_l(n+1),score_r(n+1);
	rep(i,n){
		score_l[i+1]=score_l[i]+v[i];
		score_r[i+1]=score_r[i]+v[n-i-1];
	}
	rep(i,n){
		score_l[i+1]-=x[i];
		score_r[i+1]-=L-x[n-i-1];
	}
	sparse_table<lint> Sl=score_l,Sr=score_r;

	lint ans=max(Sl.query(0,n+1),Sr.query(0,n+1));
	rep(i,n-1){
		ans=max(ans,score_l[i+1]-x[i]+Sr.query(0,n-i));
		ans=max(ans,score_r[i+1]-(L-x[n-i-1])+Sl.query(0,n-i));
	}
	printf("%lld\n",ans);

	return 0;
}
