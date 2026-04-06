#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	vector<int> a;
public:
	union_find(int n):a(n,-1){}
	int find(int x){
		if(a[x]<0) return x;
		return a[x]=find(a[x]);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){ a[x]+=a[y]; a[y]=x; }
	}
	int size(int x){ return -a[find(x)]; }
};

const int L=100000;

int main(){
	int n; scanf("%d",&n);

	union_find U(2*L);
	vector<int> x(n),y(n);
	rep(i,n){
		scanf("%d%d",&x[i],&y[i]); x[i]--; y[i]--;
		U.unite(x[i],y[i]+L);
	}

	map<int,pair<int,int>> Cnt;
	set<int> Sx,Sy;
	rep(i,n){
		if(Sx.count(x[i])==0){
			++Cnt[U.find(x[i])].first;
			Sx.emplace(x[i]);
		}
		if(Sy.count(y[i])==0){
			++Cnt[U.find(y[i]+L)].second;
			Sy.emplace(y[i]);
		}
	}

	long long res=0;
	for(auto a:Cnt){
		res+=1LL*a.second.first*a.second.second;
	}
	printf("%lld\n",res-n);

	return 0;
}
