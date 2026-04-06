#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> h(n);
	rep(i,n) scanf("%d",&h[i]);

	int ans=1,pre=0;
	rep(i,n){
		if(i>=2 && h[i-2]>h[i-1] && h[i-1]<h[i]) pre=i-1;
		ans=max(ans,i-pre+1);
	}
	printf("%d\n",ans);

	return 0;
}
