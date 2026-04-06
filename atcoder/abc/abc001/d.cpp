#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	bool r[24*60+1]={};
	rep(i,n){
		char s[10]; scanf("%s",s);
		int a=(s[0]-'0')*10+(s[1]-'0');
		int b=(s[2]-'0')*10+(s[3]-'0');
		int c=(s[5]-'0')*10+(s[6]-'0');
		int d=(s[7]-'0')*10+(s[8]-'0');

		int x=a*60+b,y=c*60+d;
		if(x%10<5) x=x/10*10; else x=x/10*10+5;
		if(y%10>5) y=y/10*10+10; else if(y%10==0) y=y/10*10; else y=y/10*10+5;
		for(int i=x;i<y;i++) r[i]=true;
	}

	int pre;
	rep(i,24*60+1){
		if((i==0 || !r[i-1]) && r[i]) pre=i;
		else if(i>0 && r[i-1] && !r[i]){
			int x=pre,y=i;
			int a=x/60,b=x%60,c=y/60,d=y%60;
			printf("%02d%02d-%02d%02d\n",a,b,c,d);
		}
	}

	return 0;
}
