#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

weighted_graph<int> T;
vector<int> color;

void dfs(int u,int p,int c_pre){
	int idx=0;
	if(idx==c_pre) idx++;

	for(auto e:T[u]){
		int v=e.to,id=e.wt;
		if(v!=p){
			color[id]=idx++; if(idx==c_pre) idx++;
			dfs(v,u,color[id]);
		}
	}
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v,i);
		T[v].emplace_back(u,i);
	}

	color.resize(n-1,-1);
	dfs(0,-1,-1);

	printf("%d\n",*max_element(color.begin(),color.end())+1);
	rep(i,n-1) printf("%d\n",color[i]+1);

	return 0;
}
