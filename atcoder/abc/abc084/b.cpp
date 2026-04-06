#include <algorithm>
#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b;
	char s[16];
	scanf("%d%d%s",&a,&b,s);

	puts(count(s,s+a+b+1,'-')==1&&s[a]=='-'?"Yes":"No");

	return 0;
}
