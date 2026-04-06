#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> sum(n+1);
	rep(_,q){
		int l,r; scanf("%d%d",&l,&r); l--;
		sum[l]^=1;
		sum[r]^=1;
	}

	rep(i,n){
		sum[i+1]^=sum[i];
		putchar('0'+sum[i]);
	}
	puts("");

	return 0;
}
