#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s;
	int type; cin>>s>>type;

	int x=0,y=0,q=0;
	for(char c:s){
		if     (c=='L') x--;
		else if(c=='R') x++;
		else if(c=='U') y++;
		else if(c=='D') y--;
		else            q++;
	}

	if(type==1) printf("%d\n",abs(x)+abs(y)+q);
	else{
		if(q<=abs(x)+abs(y)) printf("%d\n",abs(x)+abs(y)-q);
		else                 printf("%d\n",(q-abs(x)+abs(y))%2);
	}

	return 0;
}
