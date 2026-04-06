#include <cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);

	int ans=0;
	for(int i=1;i<=n;i++){
		char s[8]; sprintf(s,"%d",i);
		int cnt=0;
		for(int j=0;s[j];j++) cnt+=s[j]-'0';
		if(a<=cnt && cnt<=b) ans+=i;
	}
	printf("%d\n",ans);

	return 0;
}
