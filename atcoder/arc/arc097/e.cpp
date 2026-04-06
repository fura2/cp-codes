#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,G val){
		for(;i<a.size();i|=i+1) a[i]+=val;
	}
	G sum(int l,int r){
		if(l==0){
			G res{};
			for(r--;r>=0;r=(r&(r+1))-1) res+=a[r];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
};

int main(){
	int n; cin>>n;

	int pos[2][2000];
	rep(i,2*n){
		char c;
		int a; cin>>c>>a; a--;
		if(c=='W') pos[0][a]=i;
		else       pos[1][a]=i;
	}

	static int dp[2001][2001];
	rep(i,n+1) rep(j,n+1) dp[i][j]=INF;
	dp[0][0]=0;

	Fenwick_tree<int> F0(2*n);
	rep(i,n+1){
		Fenwick_tree<int> F1(2*n);
		rep(j,n+1){
			if(i<n){ // append (white, i)
				int x=pos[0][i];
				int cost=x-F0.sum(0,x)-F1.sum(0,x);
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+cost);
			}
			if(j<n){ // append (black, j)
				int x=pos[1][j];
				int cost=x-F0.sum(0,x)-F1.sum(0,x);
				dp[i][j+1]=min(dp[i][j+1],dp[i][j]+cost);
			}
			F1.add(pos[1][j],1);
		}
		F0.add(pos[0][i],1);
	}

	cout<<dp[n][n]<<endl;

	return 0;
}
