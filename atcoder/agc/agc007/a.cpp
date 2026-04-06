#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);

	int cnt=0;
	rep(i,h){
		char s[9]; scanf("%s",s);
		cnt+=count(s,s+w,'#');
	}
	puts(cnt==h+w-1?"Possible":"Impossible");

	return 0;
}
