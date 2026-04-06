#include <cstdio>
#include <cstring>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	scanf("%d",&n);

	int ans=0;
	for(int i=1;i<=n;i++){
		char s[8];
		sprintf(s,"%d",i);
		if(strlen(s)%2==1) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
