#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m);
	rep(i,m) scanf("%d",&a[i]), a[i]--;

	vector<bool> used(n);
	for(int i=m-1;i>=0;i--) if(!used[a[i]]) {
		used[a[i]]=true;
		printf("%d\n",a[i]+1);
	}
	rep(i,n) if(!used[i]) printf("%d\n",i+1);

	return 0;
}
