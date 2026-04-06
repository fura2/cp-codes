#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int a[11]={1};
	rep(i,10) a[i+1]=a[i]*(i+1);

	int ans=0;
	for(int i=10;i>=1;i--){
		ans+=n/a[i];
		n%=a[i];
	}
	printf("%d\n",ans);

	return 0;
}
