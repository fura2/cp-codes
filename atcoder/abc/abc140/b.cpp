#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[50],b[50],c[49];
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i), a[i]--;
	rep(i,n) scanf("%d",b+i);
	rep(i,n-1) scanf("%d",c+i);

	int ans=0;
	rep(i,n){
		ans+=b[a[i]];
		if(i<n-1 && a[i]+1==a[i+1]) ans+=c[a[i]];
	}
	printf("%d\n",ans);

	return 0;
}
