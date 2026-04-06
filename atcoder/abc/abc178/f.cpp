#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;
	rep(i,n) scanf("%d",&b[i]), b[i]--;

	vector fa(n,0),fb(n,0);
	vector pos(n,vector<int>());
	rep(i,n){
		fa[a[i]]++;
		fb[b[i]]++;
		pos[a[i]].emplace_back(i);
	}

	int mx=0;
	rep(x,n) mx=max(mx,fa[x]+fb[x]);
	if(mx>n){
		puts("No");
		return 0;
	}

	priority_queue<pair<int,int>> Q;
	rep(x,n) if(fa[x]>0 && fb[x]>0) Q.emplace(fa[x]+fb[x],x);

	vector<int> ans(n,-1);
	while(Q.size()>=2){
		int x=Q.top().second; Q.pop();
		int y=Q.top().second; Q.pop();

		int p=pos[x].back(); pos[x].pop_back();
		int q=pos[y].back(); pos[y].pop_back();
		ans[p]=y;
		ans[q]=x;

		fa[x]--; fb[x]--;
		fa[y]--; fb[y]--;
		if(fa[x]>0 && fb[x]>0) Q.emplace(fa[x]+fb[x],x);
		if(fa[y]>0 && fb[y]>0) Q.emplace(fa[y]+fb[y],y);
	}

	deque<int> Da,Db;
	if(Q.size()==1){
		int x=Q.top().second; Q.pop();
		rep(_,fa[x]) Da.emplace_back(x);
		rep(_,fb[x]) Db.emplace_front(x);
		fa[x]=fb[x]=0;
	}
	rep(x,n) rep(_,fa[x]) Da.emplace_back(x);
	rep(x,n) rep(_,fb[x]) Db.emplace_front(x);
	assert(Da.size()==Db.size());
	rep(i,Da.size()){
		ans[pos[Da[i]].back()]=Db[i];
		pos[Da[i]].pop_back();
	}

	puts("Yes");
	rep(i,n) printf("%d%c",ans[i]+1,i<n-1?' ':'\n');

	return 0;
}
