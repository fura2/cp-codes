#include <algorithm>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,v[50];
	scanf("%d",&n);
	rep(i,n) scanf("%d",v+i);

	sort(v,v+n);

	double ans=v[0];
	rep(i,n-1) ans=(ans+v[i+1])/2;
	printf("%f\n",ans);

	return 0;
}
