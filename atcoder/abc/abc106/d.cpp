#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
class Fenwick_tree{
	vector<T> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,T val){
		for(;i<a.size();i|=i+1) a[i]+=val;
	}
	T sum(int i,int j){
		if(i==0){
			T res{};
			for(j--;j>=0;j=(j&(j+1))-1) res+=a[j];
			return res;
		}
		return sum(0,j)-sum(0,i);
	}
};

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);

	vector<pair<int,int>> Event[500];
	pair<int,int> I[200000],Q[100000];
	rep(i,m){
		scanf("%d%d",&I[i].first,&I[i].second);
		I[i].first--; I[i].second--;
		Event[I[i].first].emplace_back(0,i);
	}
	rep(i,q){
		scanf("%d%d",&Q[i].first,&Q[i].second);
		Q[i].first--; Q[i].second--;
		Event[Q[i].first].emplace_back(1,i);
	}

	int ans[100000];
	Fenwick_tree<int> F(n);
	for(int i=n-1;i>=0;i--) if(!Event[i].empty()) {
		for(auto a:Event[i]){
			int id=a.second;
			if(a.first==0){
				F.add(I[id].second,1);
			}
			else{
				ans[id]=F.sum(Q[id].first,Q[id].second+1);
			}
		}
	}

	rep(i,q) printf("%d\n",ans[i]);

	return 0;
}
