#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(n),c(n),d(m),e(m),f(m);
	rep(i,n) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	rep(j,m) scanf("%d%d%d",&d[j],&e[j],&f[j]);

	vector<int> X={0},Y={0};
	rep(i,n){
		X.emplace_back(2*c[i]-2);
		X.emplace_back(2*c[i]-1);
		X.emplace_back(2*c[i]);
		Y.emplace_back(2*a[i]-2);
		Y.emplace_back(2*a[i]);
		Y.emplace_back(2*b[i]-2);
		Y.emplace_back(2*b[i]);
	}
	rep(j,m){
		Y.emplace_back(2*d[j]-2);
		Y.emplace_back(2*d[j]-1);
		Y.emplace_back(2*d[j]);
		X.emplace_back(2*e[j]-2);
		X.emplace_back(2*e[j]);
		X.emplace_back(2*f[j]-2);
		X.emplace_back(2*f[j]);
	}

	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());

	int sx=lower_bound(X.begin(),X.end(),0)-X.begin();
	int sy=lower_bound(Y.begin(),Y.end(),0)-Y.begin();

	int h=Y.size(),w=X.size();
	vector<vector<int>> B(h,vector<int>(w)); // 0: not visited, 1: visited, 2: wall
	B[sy][sx]=1;

	rep(i,n){
		int y0=lower_bound(Y.begin(),Y.end(),2*a[i])-Y.begin();
		int y1=lower_bound(Y.begin(),Y.end(),2*b[i])-Y.begin();
		int x =lower_bound(X.begin(),X.end(),2*c[i]-1)-X.begin();
		for(int y=y0;y<y1;y++) B[y][x]=2;
	}
	rep(j,m){
		int x0=lower_bound(X.begin(),X.end(),2*e[j])-X.begin();
		int x1=lower_bound(X.begin(),X.end(),2*f[j])-X.begin();
		int y =lower_bound(Y.begin(),Y.end(),2*d[j]-1)-Y.begin();
		for(int x=x0;x<x1;x++) B[y][x]=2;
	}

	queue<pair<int,int>> Q;
	Q.emplace(sy,sx);
	while(!Q.empty()){
		int y,x; tie(y,x)=Q.front(); Q.pop();
		rep(k,4){
			int y2=y+dy[k],x2=x+dx[k];
			if(0<=y2 && y2<h && 0<=x2 && x2<w && B[y2][x2]==0){
				B[y2][x2]=1;
				Q.emplace(y2,x2);
			}
		}
	}

	if(B[0][0]==1) return puts("INF"),0;

	lint ans=0;
	rep(i,h) rep(j,w) if(B[i][j]==1) {
		assert(i<h-1 && j<w-1);
		lint y0=Y[i],y1=Y[i+1];
		lint x0=X[j],x1=X[j+1];
		if(y0%2!=0 || x0%2!=0) continue;
		if(y1%2!=0) y1++;
		if(x1%2!=0) x1++;
		ans+=(y1-y0)*(x1-x0)/4;
	}
	printf("%lld\n",ans);

	return 0;
}
