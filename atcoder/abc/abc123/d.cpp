#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n[3];
lint a[3][1000];

struct state{
	int i,j,k;
	state(int i,int j,int k):i(i),j(j),k(k){}
	int &operator[](int l){
		if     (l==0) return i;
		else if(l==1) return j;
		else          return k;
	}
};

lint value(state x){
	lint res=0;
	rep(i,3) res+=a[i][x[i]];
	return res;
}

bool operator<(state x,state y){
	if(value(x)!=value(y)) return value(x)<value(y);
	return tie(x[0],x[1],x[2])<tie(y[0],y[1],y[2]);
}

int main(){
	rep(i,3) cin>>n[i];
	int k; cin>>k;
	rep(i,3){
		rep(j,n[i]) cin>>a[i][j];
		sort(a[i],a[i]+n[i],greater<lint>());
	}

	priority_queue<state> Q;
	Q.emplace(0,0,0);
	set<state> Vis;
	Vis.emplace(0,0,0);
	rep(_,k){
		auto x=Q.top(); Q.pop();
		cout<<value(x)<<endl;
		rep(i,3) if(x[i]<n[i]-1) {
			x[i]++;
			if(Vis.count(x)==0){
				Q.emplace(x);
				Vis.emplace(x);
			}
			x[i]--;
		}
	}

	return 0;
}
