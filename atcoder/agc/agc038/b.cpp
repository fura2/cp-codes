#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> a;
public:
	union_find(int N):a(N,-1),n(N){}
	int find(int x){
		if(a[x]<0) return x;
		return a[x]=find(a[x]);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){ a[x]+=a[y]; a[y]=x; n--; }
	}
	int size(){ return n; }
	int size(int x){ return -a[find(x)]; }
};

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> p(n);
	rep(i,n) scanf("%d",&p[i]);

	union_find U(n-k+1);
	set<int> S(p.begin(),p.begin()+k);
	rep(i,n-k){
		if(*S.begin()==p[i] && *S.rbegin()<p[k+i]) U.unite(i,i+1);
		S.erase(p[i]);
		S.emplace(p[k+i]);
	}

	vector<int> flag(n-1);
	rep(i,n-1) flag[i]=(p[i]<p[i+1]);
	vector<int> sorted;
	int cnt=0;
	rep(i,n-1){
		if(flag[i]) cnt++;
		else        cnt=0;
		if(cnt>=k-1) sorted.emplace_back(i-k+2);
	}
	for(int i=1;i<sorted.size();i++) U.unite(sorted[0],sorted[i]);

	printf("%d\n",U.size());

	return 0;
}
