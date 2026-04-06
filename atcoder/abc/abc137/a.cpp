#include <algorithm>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",max({a+b,a-b,a*b}));

	return 0;
}
