#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

using matching=vector<pair<int,int>>;

int h,w;

vector<matching> M; // all matchings of rows

void dfs(int i,int mask,bool center,matching& tmp){
	if(mask==(1<<h)-1){
		M.emplace_back(tmp);
		return;
	}

	if(mask>>i&1) return dfs(i+1,mask,center,tmp);

	for(int j=i+1;j<h;j++) if((mask>>j&1)==0) {
		tmp.emplace_back(i,j);
		dfs(i+1,mask|1<<i|1<<j,center,tmp);
		tmp.pop_back();
	}
	if(h%2==1 && !center){
		tmp.emplace_back(i,i);
		dfs(i+1,mask|1<<i,true,tmp);
		tmp.pop_back();
	}
}

graph G;
int memo[1<<12][2];

bool dfs2(int u,int mask,bool center){
	int& res=memo[mask][center];
	if(res!=-1) return res;

	if(mask==(1<<w)-1) return res=true;
	if(u==w) return res=false;

	if(mask>>u&1) return res=dfs2(u+1,mask,center);

	for(int v:G[u]) if((mask>>v&1)==0) {
		if(u!=v){
			if(dfs2(u+1,mask|1<<u|1<<v,center)) return res=true;
		}
		else if(w%2==1 && !center){
			if(dfs2(u+1,mask|1<<u,true)) return res=true;
		}
	}
	return res=false;
}

int main(){
	char B[12][13];
	scanf("%d%d",&h,&w);
	rep(i,h) scanf("%s",B[i]);

	{
		matching tmp;
		dfs(0,0,false,tmp);
	}

	for(const auto& mat:M){
		G=graph(w);
		rep(u,w) for(int v=u;v<w;v++) {
			bool ok=true;
			rep(i,mat.size()){
				int r1,r2; tie(r1,r2)=mat[i];
				if(B[r1][u]!=B[r2][v] || B[r1][v]!=B[r2][u]){ ok=false; break; }
			}
			if(ok){
				G[u].emplace_back(v);
				if(u<v) G[v].emplace_back(u);
			}
		}

		memset(memo,-1,sizeof memo);
		if(dfs2(0,0,false)) return puts("YES"),0;
	}
	puts("NO");

	return 0;
}
