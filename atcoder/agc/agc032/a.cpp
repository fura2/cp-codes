#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	vector<int> ans(n);
	for(int i=n-1;i>=0;i--){
		int j;
		for(j=i;j>=0;j--) if(a[j]==j) break;
		if(j<0) return puts("-1"),0;
		a.erase(a.begin()+j);
		ans[i]=j;
	}

	rep(i,n) printf("%d\n",ans[i]+1);

	return 0;
}
