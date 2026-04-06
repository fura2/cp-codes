#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	double a[100];
	scanf("%d",&n);
	rep(i,n) scanf("%lf",a+i);

	double ans=0;
	rep(i,n) ans+=1/a[i];
	printf("%f\n",1/ans);

	return 0;
}
