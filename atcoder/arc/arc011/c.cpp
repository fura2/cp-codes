#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t;
	int n; cin>>s>>t>>n;

	string S[1002];
	rep(i,n){
		cin>>S[i];
		if(S[i]==s || S[i]==t) n--, i--;
	}
	S[n]=s;
	S[n+1]=t;

	vector<int> G[1002];
	rep(i,n+2) rep(j,n+2) {
		int cnt=0;
		rep(k,S[i].length()) if(S[i][k]!=S[j][k]) cnt++;
		if(cnt<=1) G[i].emplace_back(j);
	}

	int d[1002],prev[1002];
	rep(u,1002) d[u]=-1;
	d[n]=0;
	queue<int> Q; Q.push(n);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==-1) {
			d[v]=d[u]+1;
			Q.push(v);
			prev[v]=u;
		}
	}

	if(d[n+1]==-1){
		cout<<-1<<endl;
	}
	else{
		vector<int> path={n+1};
		int u=n+1;
		do{
			u=prev[u];
			path.emplace_back(u);
		}while(u!=n);
		reverse(path.begin(),path.end());

		cout<<path.size()-2<<endl;
		for(int i:path) cout<<S[i]<<endl;
	}

	return 0;
}
