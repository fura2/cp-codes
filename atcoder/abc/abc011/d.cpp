#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d,x,y; scanf("%d%d%d%d",&n,&d,&x,&y);

	if(x%d!=0 || y%d!=0) return puts("0"),0;

	x=abs(x)/d;
	y=abs(y)/d;

	double ans=0;
	rep(i,n+1) if(x<=i && (i-x)%2==0 && y<=n-i && (n-i-y)%2==0) {
		int a=(i-x)/2,b=(n-i-y)/2; // a+x 回右, a 回左, b+y 回上, b 回下

		double tmp=1;
		int num=n;
		rep(j,a+x) tmp*=num/(4.0*(a+x-j)), num--;
		rep(j, a ) tmp*=num/(4.0*( a -j)), num--;
		rep(j,b+y) tmp*=num/(4.0*(b+y-j)), num--;
		rep(j, b ) tmp*=num/(4.0*( b -j)), num--;
		ans+=tmp;
	}
	printf("%.15f\n",ans);

	return 0;
}
