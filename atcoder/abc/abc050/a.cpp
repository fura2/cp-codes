#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b;
	char c; scanf("%d %c%d",&a,&c,&b);
	printf("%d\n",c=='+'?a+b:a-b);
	return 0;
}
