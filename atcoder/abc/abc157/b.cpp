#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[3][3];
	rep(i,3) rep(j,3) scanf("%d",&a[i][j]);

	int n; scanf("%d",&n);
	rep(i,n){
		int b; scanf("%d",&b);
		rep(y,3) rep(x,3) if(a[y][x]==b) a[y][x]=0;
	}

	rep(i,3){
		int cnt=0;
		rep(j,3) if(a[i][j]==0) cnt++;
		if(cnt==3) return puts("Yes"),0;
	}
	rep(j,3){
		int cnt=0;
		rep(i,3) if(a[i][j]==0) cnt++;
		if(cnt==3) return puts("Yes"),0;
	}
	{
		int cnt=0;
		rep(i,3) if(a[i][i]==0) cnt++;
		if(cnt==3) return puts("Yes"),0;
	}
	{
		int cnt=0;
		rep(i,3) if(a[i][2-i]==0) cnt++;
		if(cnt==3) return puts("Yes"),0;
	}

	puts("No");

	return 0;
}
