#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	char s[4],t[4];
	scanf("%s%s",s,t);

	int cnt=0;
	rep(i,3) if(s[i]==t[i]) cnt++;
	printf("%d\n",cnt);

	return 0;
}
