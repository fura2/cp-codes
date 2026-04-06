#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,c; scanf("%d%d",&n,&c);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	int ans=1e9;
	rep(x,10) rep(y,10) if(x!=y) {
		int tmp=0;
		rep(i,n){
			if(i%2==0 && a[i]!=x) tmp+=c;
			if(i%2==1 && a[i]!=y) tmp+=c;
		}
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);

	return 0;
}
