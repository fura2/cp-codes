#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,s,t,w; scanf("%d%d%d%d",&n,&s,&t,&w);

	int ans=0;
	rep(i,n){
		if(s<=w && w<=t) ans++;
		if(i<n-1){
			int a; scanf("%d",&a);
			w+=a;
		}
	}
	printf("%d\n",ans);

	return 0;
}
