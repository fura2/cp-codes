#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	char B[500][501];
	rep(i,h) scanf("%s",B[i]);

	int sum[500][501]={};
	rep(i,h) rep(j,w) sum[i][j+1]=sum[i][j]+(B[i][j]=='o'?1:0);

	int ans=0;
	for(int i=k-1;i<=h-k;i++) for(int j=k-1;j<=w-k;j++) {
		bool ok=true;
		for(int d=-k+1;d<0;d++){
			if(sum[i+d][j+d+k]-sum[i+d][j-(d+k)+1]!=2*(d+k)-1) ok=false;
		}
		rep(d,k){
			if(sum[i+d][j+k-d]-sum[i+d][j-(k-d)+1]!=2*(k-d)-1) ok=false;
		}
		if(ok) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
