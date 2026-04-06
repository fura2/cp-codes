#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int dfs2(vector<int> Z,vector<int> O,int b){
	if(b==-1) return 0;

	vector<int> ZZ,ZO,OZ,OO;
	rep(i,Z.size()){
		if(Z[i]>>b&1) ZO.emplace_back(Z[i]);
		else          ZZ.emplace_back(Z[i]);
	}
	rep(i,O.size()){
		if(O[i]>>b&1) OO.emplace_back(O[i]);
		else          OZ.emplace_back(O[i]);
	}

	int res=INT_MAX;
	bool good=false;
	if(ZZ.size()>0 && OZ.size()>0){
		res=min(res,dfs2(ZZ,OZ,b-1));
		good=true;
	}
	if(ZO.size()>0 && OO.size()>0){
		res=min(res,dfs2(ZO,OO,b-1));
		good=true;
	}
	if(!good){
		if(ZZ.size()>0 && OO.size()>0) res=min(res,dfs2(ZZ,OO,b-1)+(1<<b));
		if(ZO.size()>0 && OZ.size()>0) res=min(res,dfs2(ZO,OZ,b-1)+(1<<b));
	}
	return res;
}

int dfs(vector<int> a,int b){
	int n=a.size();

	if(n==0 || b==-1) return 0;

	vector<int> Z,O;
	rep(i,n){
		if(a[i]>>b&1) O.emplace_back(a[i]);
		else          Z.emplace_back(a[i]);
	}
	if(Z.size()%2==0 && O.size()%2==0){
		return max(dfs(Z,b-1),dfs(O,b-1));
	}
	else{
		return dfs2(Z,O,b-1)+(1<<b);
	}
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(2*n);
	rep(i,2*n) scanf("%d",&a[i]);

	printf("%lld\n",dfs(a,30));

	return 0;
}
