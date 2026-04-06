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

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> p(n),pos(n);
	rep(i,n){
		scanf("%d",&p[i]); p[i]--;
		pos[p[i]]=i;
	}

	vector<int> even(n,INF),odd(n,INF);
	rep(i,n) (i%2==0?even:odd)[i]=p[i];
	sparse_table<int> RMQ[2]={even,odd};

	vector<bool> used(n);
	Fenwick_tree<int> F(n); // F[i] = 1 if p[i] is used, = 0 otherwise

	priority_queue<int,vector<int>,greater<int>> Q;
	Q.emplace(RMQ[0].query(0,n));

	vector<int> ans;
	while(ans.size()<n){
		int x,i,l;
		while(1){
			x=Q.top(); Q.pop();
			i=pos[x];
			if(used[i]) continue;

			l=F.lower_bound(F.sum(0,i+1));
			if(used[l]) l++;
			if((i-l)%2==1) continue; // i の左にできる区間が奇数長

			break;
		}

		int r=F.upper_bound(F.sum(0,i+1));
		int y=RMQ[(i+1)%2].query(i+1,r);
		int j=pos[y];

		used[i]=used[j]=true;
		F.add(i,1);
		F.add(j,1);
		ans.emplace_back(x);
		ans.emplace_back(y);

		// Q に区間 (i, j) での次の候補を追加
		if(i+1<j){
			Q.emplace(RMQ[(i+1)%2].query(i+1,j));
		}
		// Q に区間 [l, i) での次の候補を追加
		if(l<i){
			Q.emplace(RMQ[l%2].query(l,i));
		}
		// Q に区間 (j, r) での次の候補を追加
		if(j+1<r){
			Q.emplace(RMQ[(j+1)%2].query(j+1,r));
		}
	}

	rep(i,n) printf("%d%c",ans[i]+1,i<n-1?' ':'\n');

	return 0;
}
