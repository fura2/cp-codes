#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

/*
int g[100][100];

int dfs(int i,int j){
	if(g[i][j]!=-1) return g[i][j];
	set<int> S;
	for(int k=1;2*k<=i;k++) S.emplace(dfs(i-2*k,j+k));
	for(int k=1;2*k<=j;k++) S.emplace(dfs(i+k,j-2*k));
	for(int k=0;;k++) if(S.count(k)==0) return g[i][j]=k;
}
*/

int main(){
/*
	rep(i,100) rep(j,100) g[i][j]=-1;
	rep(i,60) rep(j,60) dfs(i,j);
	rep(i,40){ rep(j,40) printf("%2d ",g[i][j]); puts(""); }
*/
	long long x,y; cin>>x>>y;
	cout<<(abs(x-y)>1?"Alice":"Brown")<<endl;
	return 0;
}
