#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int n;
lint v[200000];
char c[200000];

int pre[3][200000];

lint memo[200001][2][2][2][2][2][2];

// rs, gs, bs: 同じ色とマッチングするために保留にしている R, G, B の個数
// rd, gd, bd: 異なる色とマッチングするために保留にしている R, G, B の個数
lint dfs(int i,int rs,int gs,int bs,int rd,int gd,int bd){
	lint& res=memo[i][rs][gs][bs][rd][gd][bd];
	if(res!=-1) return res;

	res=INF;
	if(i==n){
		if(rs+gs+bs+rd+gd+bd==0) res=0;
		return res;
	}

	if(c[i]=='R'){
		// R とマッチ
		if(rs==1) res=min(res,dfs(i+1,0,gs,bs,rd,gd,bd));
		// あとで R 以外とマッチさせる
		if(rd==0) res=min(res,dfs(i+1,rs,gs,bs,1,gd,bd));
		// あとで R とマッチさせる
		if(rd==0 && rs==0) res=min(res,dfs(i+1,1,gs,bs,rd,gd,bd));
		// G とマッチ
		if(rd==0 && gd==1) res=min(res,dfs(i+1,rs,gs,bs,0,0,bd)+abs(v[i]-v[pre[1][i]]));
		// B とマッチ
		if(rd==0 && bd==1) res=min(res,dfs(i+1,rs,gs,bs,0,gd,0)+abs(v[i]-v[pre[2][i]]));
	}
	if(c[i]=='G'){
		if(gs==1) res=min(res,dfs(i+1,rs,0,bs,rd,gd,bd));
		if(gd==0) res=min(res,dfs(i+1,rs,gs,bs,rd,1,bd));
		if(gd==0 && gs==0) res=min(res,dfs(i+1,rs,1,bs,rd,gd,bd));
		if(gd==0 && rd==1) res=min(res,dfs(i+1,rs,gs,bs,0,0,bd)+abs(v[i]-v[pre[0][i]]));
		if(gd==0 && bd==1) res=min(res,dfs(i+1,rs,gs,bs,rd,0,0)+abs(v[i]-v[pre[2][i]]));
	}
	if(c[i]=='B'){
		if(bs==1) res=min(res,dfs(i+1,rs,gs,0,rd,gd,bd));
		if(bd==0) res=min(res,dfs(i+1,rs,gs,bs,rd,gd,1));
		if(bd==0 && bs==0) res=min(res,dfs(i+1,rs,gs,1,rd,gd,bd));
		if(bd==0 && rd==1) res=min(res,dfs(i+1,rs,gs,bs,0,gd,0)+abs(v[i]-v[pre[0][i]]));
		if(bd==0 && gd==1) res=min(res,dfs(i+1,rs,gs,bs,rd,0,0)+abs(v[i]-v[pre[1][i]]));
	}
	return res;
}

int main(){
	scanf("%d",&n);
	n*=2;
	vector<pair<lint,char>> p(n);
	rep(i,n) scanf("%lld %c",&p[i].first,&p[i].second);
	sort(p.begin(),p.end());
	rep(i,n) tie(v[i],c[i])=p[i];

	rep(i,n){
		if(i==0){
			rep(k,3) pre[k][0]=-1;
		}
		else{
			rep(k,3) pre[k][i]=pre[k][i-1];
		}
		if(c[i]=='R') pre[0][i]=i;
		if(c[i]=='G') pre[1][i]=i;
		if(c[i]=='B') pre[2][i]=i;
	}

	memset(memo,-1,sizeof memo);
	printf("%lld\n",dfs(0,0,0,0,0,0,0));

	return 0;
}
