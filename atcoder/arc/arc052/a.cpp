#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int ans=0;
	while(1){
		int c=getchar();
		if(c==EOF) break;
		if(isdigit(c)) ans=10*ans+c-'0';
	}
	printf("%d\n",ans);
	return 0;
}
