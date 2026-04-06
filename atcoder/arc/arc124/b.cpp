#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	set<int> ans;
	rep(i,n){
		int x=a[0]^b[i];
		multiset<int> S,T;
		rep(j,n) if(j!=0) {
			S.emplace(a[j]^x);
		}
		rep(j,n) if(j!=i) {
			T.emplace(b[j]);
		}
		if(S==T) ans.emplace(x);
	}

	printf("%ld\n",ans.size());
	for(int x:ans) printf("%d\n",x);

	return 0;
}
