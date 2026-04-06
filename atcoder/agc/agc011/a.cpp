#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,c,k; scanf("%d%d%d",&n,&c,&k);
	vector<int> T(n);
	rep(i,n) scanf("%d",&T[i]);

	sort(T.begin(),T.end());

	int ans=0;
	queue<int> Q;
	rep(i,n) Q.emplace(T[i]);
	while(!Q.empty()){
		int t=Q.front()+k;
		rep(i,c){
			if(Q.empty() || t<Q.front()) break;
			Q.pop();
		}
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}
