#include <algorithm>
#include <cstdio>
#include <cstring>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	for(int i=n;;i++){
		char s[8];
		sprintf(s,"%d",i);
		int len=strlen(s);
		if(count(s,s+len,s[0])==len){
			printf("%d\n",i);
			break;
		}
	}

	return 0;
}
