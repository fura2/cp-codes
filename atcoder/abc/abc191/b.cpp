#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> ans;
	rep(i,n) if(a[i]!=x) ans.emplace_back(a[i]);
	rep(i,ans.size()) printf("%d%s",ans[i],i+1<ans.size()?" ":"");
	puts("");

	return 0;
}
