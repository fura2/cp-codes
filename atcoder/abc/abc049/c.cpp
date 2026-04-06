#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	char s[100001];
	scanf("%s",s);
	int n=strlen(s);

	while(1){
		if     (n>=5 && strcmp(s+n-5,"dream"  )==0) n-=5, s[n]='\0';
		else if(n>=7 && strcmp(s+n-7,"dreamer")==0) n-=7, s[n]='\0';
		else if(n>=5 && strcmp(s+n-5,"erase"  )==0) n-=5, s[n]='\0';
		else if(n>=6 && strcmp(s+n-6,"eraser" )==0) n-=6, s[n]='\0';
		else break;
	}
	puts(n>0?"NO":"YES");

	return 0;
}
