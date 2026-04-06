#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; scanf("%d",&q);

	int ans=0;
	rep(_,q){
		int a,k; scanf("%d%d",&a,&k);
		while(a%k!=0){
			int d=a/k+1;
			a-=max((a%k)/d,1)*d;
		}
		ans^=a/k;
	}
	puts(ans>0?"Takahashi":"Aoki");

	return 0;
}
