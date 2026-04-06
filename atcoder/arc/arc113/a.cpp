#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k; scanf("%d",&k);

	int ans=0;
	for(int a=1;a<=k;a++){
		for(int b=1;b<=k/a;b++){
			ans+=k/a/b;
		}
	}
	printf("%d\n",ans);

	return 0;
}
