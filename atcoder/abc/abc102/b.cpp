#include <algorithm>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[100];
	scanf("%d",&n);
	rep(i,n) scanf("%d",a+i);

	sort(a,a+n);

	printf("%d\n",a[n-1]-a[0]);

	return 0;
}
