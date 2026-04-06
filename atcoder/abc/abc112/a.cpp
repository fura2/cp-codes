#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	if(n==1) puts("Hello World");
	else{
		int a,b; scanf("%d%d",&a,&b);
		printf("%d\n",a+b);
	}
	return 0;
}
