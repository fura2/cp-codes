#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int sgn(lint x){
	if(x>0) return 1;
	if(x<0) return -1;
	return 0;
}

void solve(){
	lint ax,ay,bx,by,cx,cy;
	cin>>ax>>ay>>bx>>by>>cx>>cy;

	pair<lint,lint> a={ax,ay},b={bx,by},c={cx,cy};

	lint x_min=min({ax,bx,cx}),x_max=max({ax,bx,cx});
	lint y_min=min({ay,by,cy}),y_max=max({ay,by,cy});

	if(make_pair(x_max,y_max)!=a
	&& make_pair(x_max,y_max)!=b
	&& make_pair(x_max,y_max)!=c){ // type 0
		lint x=x_min,y=y_min;
		if(x==0 && y==0){
			puts("0");
		}
		else{
			printf("%lld\n",2*max(abs(x),abs(y))+(x==y?1:0));
		}
	}
	else if(make_pair(x_min,y_max)!=a
		 && make_pair(x_min,y_max)!=b
		 && make_pair(x_min,y_max)!=c){ // type 1

		lint x=x_max,y=y_min;
		if(x==0 && y==0){
			puts("1");
		}
		else{
			y=abs(y);
			if(x<0) x=1-x;
			if(x<y) x=y;
			if(y<x-1) y=x-1;
			printf("%lld\n",x+y);
		}
	}
	else if(make_pair(x_min,y_min)!=a
		 && make_pair(x_min,y_min)!=b
		 && make_pair(x_min,y_min)!=c){ // type 2

		lint x=x_max,y=y_max;
		if(x==0 && y==0){
			puts("2");
		}
		else{
			if(x<0) x=1-x;
			if(y<0) y=1-y;
			if(x==1 && y==1){
				puts("1");
			}
			else{
				printf("%lld\n",2*max(x,y)-(x==y&&sgn(x_max)==sgn(y_max)?0:1));
			}
		}
	}
	else{ // type 3
		lint x=x_min,y=y_max;
		if(x==0 && y==0){
			puts("1");
		}
		else{
			x=abs(x);
			if(y<0) y=1-y;
			if(y<x) y=x;
			if(x<y-1) x=y-1;
			printf("%lld\n",x+y);
		}
	}
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}

// experiment
/*
void solve(){
	int h=100,w=100;

	vector d(w,vector(h,vector(4,-1)));
	d[w/2][h/2][0]=0;
	queue<tuple<int,int,int>> Q;
	Q.emplace(w/2,h/2,0);
	while(!Q.empty()){
		int x,y,k; tie(x,y,k)=Q.front(); Q.pop();

		int dx,dy,k2;
		if(k==0){
			dx=1; dy=0; k2=1;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=0; dy=0; k2=1;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);

			dx=0; dy=1; k2=2;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=1; dy=0; k2=2;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=1; dy=1; k2=2;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);

			dx=0; dy=0; k2=3;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=0; dy=1; k2=3;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
		}
		else if(k==1){
			dx=-1; dy=0; k2=0;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=0; dy=0; k2=0;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);

			dx=0; dy=0; k2=2;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=0; dy=1; k2=2;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);

			dx=-1; dy=0; k2=3;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=-1; dy=1; k2=3;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=0; dy=1; k2=3;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
		}
		else if(k==2){
			dx=0; dy=-1; k2=0;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=-1; dy=0; k2=0;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=-1; dy=-1; k2=0;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);

			dx=0; dy=0; k2=1;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=0; dy=-1; k2=1;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);

			dx=-1; dy=0; k2=3;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=0; dy=0; k2=3;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
		}
		else{
			dx=0; dy=0; k2=0;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=0; dy=-1; k2=0;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);

			dx=1; dy=0; k2=1;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=1; dy=-1; k2=1;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=0; dy=-1; k2=1;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);

			dx=1; dy=0; k2=2;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
			dx=0; dy=0; k2=2;
			if(0<=x+dx && x+dx<w && 0<=y+dy && y+dy<h && d[x+dx][y+dy][k2]==-1) d[x+dx][y+dy][k2]=d[x][y][k]+1, Q.emplace(x+dx,y+dy,k2);
		}
	}

	rep(k,4){
		printf("k = %d:\n",k);
		for(int y=h/2+10;y>=h/2-10;y--){
			for(int x=w/2-10;x<=w/2+10;x++){
				printf("%2d ",d[x][y][k]);
			}
			puts("");
		}
	}
}
*/
