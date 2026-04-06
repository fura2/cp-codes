#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	printf("%d\n",n%2==0?n:2*n);

	return 0;
}
