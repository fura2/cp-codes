#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(2*n);
	rep(i,2*n) scanf("%lld",&a[i]);

	priority_queue<lint,vector<lint>,greater<>> Q;
	rep(i,n){
		Q.emplace(a[n-i-1]);
		Q.emplace(a[n+i]);
		Q.pop();
	}

	lint ans=0;
	while(!Q.empty()){
		ans+=Q.top();
		Q.pop();
	}
	printf("%lld\n",ans);

	return 0;
}
