#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a;
	char s[11];
	scanf("%d%s",&a,s);

	puts(a>=3200?s:"red");

	return 0;
}
