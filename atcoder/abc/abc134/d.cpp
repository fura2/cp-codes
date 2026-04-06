#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> ans(n);
	for(int i=n-1;i>=0;i--){
		int sum=0;
		for(int x=i;x<n;x+=i+1) sum=(sum+ans[x])%2;
		if(sum!=a[i]) ans[i]=1;
	}

	printf("%d\n",accumulate(ans.begin(),ans.end(),0));
	rep(i,n) if(ans[i]==1) printf("%d ",i+1);

	return 0;
}
