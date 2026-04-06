#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,k,a[500];

bool check(int d){
	int b[500];
	rep(i,n) b[i]=a[i]%d;
	sort(b,b+n);

	int sum=accumulate(b,b+n,0);
	return accumulate(b,b+n-sum/d,0)<=k;
}

int main(){
	scanf("%d%d",&n,&k);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0,sum=accumulate(a,a+n,0);
	for(int d=1;d*d<=sum;d++) if(sum%d==0) {
		if(check(  d  )) ans=max(ans,  d  );
		if(check(sum/d)) ans=max(ans,sum/d);
	}
	printf("%d\n",ans);

	return 0;
}
