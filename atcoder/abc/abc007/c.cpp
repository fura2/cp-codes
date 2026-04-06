#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

vector<int> distance(const graph& G,int s){
	const int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	return d;
}

int main(){
	int h,w; scanf("%d%d",&h,&w);
	int sy,sx,gy,gx; scanf("%d%d%d%d",&sy,&sx,&gy,&gx); sy--; sx--; gy--; gx--;
	char B[50][51];
	rep(i,h) scanf("%s",B[i]);

	graph G(h*w);
	rep(i,h) rep(j,w) if(B[i][j]=='.') {
		rep(k,4){
			int y=i+dy[k],x=j+dx[k];
			if(0<=y && y<h && 0<=x && x<w && B[y][x]=='.'){
				G[i*w+j].emplace_back(y*w+x);
			}
		}
	}

	printf("%d\n",distance(G,sy*w+sx)[gy*w+gx]);

	return 0;
}
