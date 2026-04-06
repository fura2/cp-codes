#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;

struct point{
	double x,y;
	point():x(0),y(0){}
	point(double x,double y):x(x),y(y){}
	point operator-(const point& a)const{ return point(x-a.x,y-a.y); }
};

double cross(const point& a,const point& b){ return a.x*b.y-a.y*b.x; }

struct segment{
	point a,b;
	segment(const point& a,const point& b):a(a),b(b){}
};

enum{CCW=1,CW=-1,ON=0};
int ccw(const point& a,const point& b,const point& c){
	double rdir=cross(b-a,c-a);
	if(rdir> EPS) return CCW;
	if(rdir<-EPS) return CW;
	return ON;
}

bool intersect(const segment &S1,const segment &S2){
	if(max(S1.a.x,S1.b.x)+EPS<min(S2.a.x,S2.b.x)
	|| max(S1.a.y,S1.b.y)+EPS<min(S2.a.y,S2.b.y)
	|| max(S2.a.x,S2.b.x)+EPS<min(S1.a.x,S1.b.x)
	|| max(S2.a.y,S2.b.y)+EPS<min(S1.a.y,S1.b.y)) return false;
	return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0
		&& ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;
}

int main(){
	double ax,ay,bx,by;
	int n;
	point P[100];
	scanf("%lf%lf%lf%lf%d",&ax,&ay,&bx,&by,&n);
	rep(i,n) scanf("%lf%lf",&P[i].x,&P[i].y);

	int cnt=0;
	segment S({ax,ay},{bx,by});
	rep(i,n) if(intersect(S,segment(P[i],P[(i+1)%n]))) cnt++;
	printf("%d\n",cnt/2+1);

	return 0;
}
