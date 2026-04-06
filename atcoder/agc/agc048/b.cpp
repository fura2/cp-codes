#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	lint ans=0;
	rep(i,n) ans+=b[i];

	priority_queue<lint> E,O;
	rep(i,n){
		if(i%2==0) E.emplace(a[i]-b[i]);
		else       O.emplace(a[i]-b[i]);
	}
	while(!E.empty() && !O.empty() && E.top()+O.top()>0){
		ans+=E.top()+O.top();
		E.pop();
		O.pop();
	}
	printf("%lld\n",ans);

	return 0;
}
