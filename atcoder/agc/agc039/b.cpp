#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	bool A[200][200];
	rep(u,n){
		string s; cin>>s;
		rep(v,n) A[u][v]=(s[v]=='1');
	}

	int ans=0;
	rep(r,n){
		int d[200];
		rep(u,n) d[u]=-1;
		d[r]=0;
		queue<int> Q;
		Q.push(r);
		while(!Q.empty()){
			int u=Q.front(); Q.pop();
			rep(v,n) if(A[u][v] && d[v]==-1) {
				d[v]=d[u]+1;
				Q.push(v);
			}
		}

		rep(u,n) rep(v,n) if(A[u][v] && abs(d[u]-d[v])!=1) { cout<<-1<<endl; return 0; }
		ans=max(ans,*max_element(d,d+n)+1);
	}
	cout<<ans<<endl;

	return 0;
}
