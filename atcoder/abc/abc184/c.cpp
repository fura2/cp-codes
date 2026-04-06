#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

	if(x1==x2 && y1==y2){
		puts("0");
	}
	else if(x1+y1==x2+y2 || x1-y1==x2-y2 || abs(x1-x2)+abs(y1-y2)<=3){
		puts("1");
	}
	else if((x1+y1)%2==(x2+y2)%2){
		puts("2");
	}
	else{
		int ans=3;
		for(int dx=-3;dx<=3;dx++) for(int dy=-3;dy<=3;dy++) if(abs(dx)+abs(dy)<=3) {
			int x3,y3;
			x3=x1+dx; y3=y1+dy;
			if(x3+y3==x2+y2 || x3-y3==x2-y2 || abs(x3-x2)+abs(y3-y2)<=3){
				ans=2;
			}
			x3=x2+dx; y3=y2+dy;
			if(x1+y1==x3+y3 || x1-y1==x3-y3 || abs(x1-x3)+abs(y1-y3)<=3){
				ans=2;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
