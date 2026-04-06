#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

#define AND 0
#define OR  1

pair<bool,vector<vector<int>>> solve(int n,vector<int> s,vector<int> t,vector<int> u,vector<int> v){
	vector<vector<int>> res(n,vector<int>(n,-1));

	vector<int> R,C;
	int rcnt[2]={},ccnt[2]={};
	rep(i,n){
		if(s[i]==AND && u[i]==1){
			rep(j,n) res[i][j]=1;
			rcnt[1]++;
		}
		else if(s[i]==OR && u[i]==0){
			rep(j,n) res[i][j]=0;
			rcnt[0]++;
		}
		else R.emplace_back(i);
	}
	rep(j,n){
		if(t[j]==AND && v[j]==1){
			rep(i,n) res[i][j]=1;
			ccnt[1]++;
		}
		else if(t[j]==OR && v[j]==0){
			rep(i,n) res[i][j]=0;
			ccnt[0]++;
		}
		else C.emplace_back(j);
	}

	if(R.size()==1){
		int tar=u[R[0]];
		for(int x:C){
			if(rcnt[v[x]]>0) res[R[0]][x]=tar;
			else             res[R[0]][x]=v[x];
		}
	}
	else if(C.size()==1){
		int tar=v[C[0]];
		for(int y:R){
			if(ccnt[u[y]]>0) res[y][C[0]]=tar;
			else             res[y][C[0]]=u[y];
		}
	}
	else if(R.size()>=2 && C.size()>=2){
		rep(i,R.size()) rep(j,C.size()) res[R[i]][C[j]]=(i+j)%2;
	}

	// check
	rep(i,n){
		int z;
		if(s[i]==AND){
			z=1;
			rep(j,n) z&=res[i][j];
		}
		else{
			z=0;
			rep(j,n) z|=res[i][j];
		}
		if(z!=u[i]) return {false,{}};
	}
	rep(j,n){
		int z;
		if(t[j]==AND){
			z=1;
			rep(i,n) z&=res[i][j];
		}
		else{
			z=0;
			rep(i,n) z|=res[i][j];
		}
		if(z!=v[j]) return {false,{}};
	}
	return {true,res};
}

int main(){
	int n; scanf("%d",&n);
	vector<int> s(n),t(n);
	vector<unsigned long long> u(n),v(n);
	rep(i,n) scanf("%d",&s[i]);
	rep(j,n) scanf("%d",&t[j]);
	rep(i,n) scanf("%llu",&u[i]);
	rep(j,n) scanf("%llu",&v[j]);

	unsigned long long ans[500][500]={};
	rep(b,64){
		vector<int> u2(n),v2(n);
		rep(i,n){
			u2[i]=u[i]>>b&1;
			v2[i]=v[i]>>b&1;
		}
		auto tmp=solve(n,s,t,u2,v2);
		if(!tmp.first) return puts("-1"),0;
		rep(i,n) rep(j,n) if(tmp.second[i][j]==1) ans[i][j]+=1ULL<<b;
	}
	rep(i,n) rep(j,n) printf("%llu%c",ans[i][j],j<n-1?' ':'\n');

	return 0;
}
