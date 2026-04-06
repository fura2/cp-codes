#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

struct point{
	int x,y;
	point(){}
	point(int x,int y):x(x),y(y){}
	bool operator<(const point& p)const{ return tie(x,y)<tie(p.x,p.y); }
};

set<point> Vis; // visited points
map<point,point> f[4]; // f[dir][point] := (next point)

point go(const point& p,int dir){
	point p2;
	if(f[dir].count(p)==0){
		p2.x=p.x+dx[dir];
		p2.y=p.y+dy[dir];
	}
	else{
		p2=f[dir][p];
	}
	return f[dir][p]=(Vis.count(p2)==0?p2:go(p2,dir));
}

int main(){
	int k;
	string s; cin>>k>>s;

	point p{0,0};
	for(char c:s){
		int dir;
		if     (c=='R') dir=0;
		else if(c=='U') dir=1;
		else if(c=='L') dir=2;
		else            dir=3;
		Vis.emplace(p);
		p=go(p,dir);
	}
	printf("%d %d\n",p.x,p.y);

	return 0;
}
