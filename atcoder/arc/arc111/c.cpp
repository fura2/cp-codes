#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n),p(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);
	rep(i,n) scanf("%d",&p[i]), p[i]--;

	vector<int> inv(n);
	rep(i,n) inv[p[i]]=i;

	vector<int> q(n);
	iota(q.begin(),q.end(),0);
	sort(q.begin(),q.end(),[&](int i,int j){
		return a[i]<a[j];
	});

	vector<pair<int,int>> ans;
	for(int i:q){
		if(p[i]==i) continue;
		if(a[i]<=b[p[i]]){
			puts("-1");
			return 0;
		}
		ans.emplace_back(i,inv[i]);
		p[inv[i]]=p[i];
		inv[p[i]]=inv[i];
		p[i]=i;
		inv[i]=i;
	}

	printf("%ld\n",ans.size());
	for(auto [i,j]:ans) printf("%d %d\n",i+1,j+1);

	return 0;
}
