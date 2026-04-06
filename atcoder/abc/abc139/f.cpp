#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;
const double PI=acos(-1);

struct point{
	double x,y;
	point():x(0),y(0){}
	point(double x,double y):x(x),y(y){}
	point operator+(const point &a)const{ return point(x+a.x,y+a.y); }
	point operator-(const point &a)const{ return point(x-a.x,y-a.y); }
	bool operator< (const point &a)const{ return x+EPS<a.x || (abs(x-a.x)<EPS && y+EPS<a.y); }
};

double cross(const point &a,const point &b){ return a.x*b.y-a.y*b.x; }

double abs(const point &a){ return sqrt(a.x*a.x+a.y*a.y); }

typedef vector<point> polygon;

enum{CCW=1,CW=-1,ON=0};
int ccw(const point &a,const point &b,const point &c){
	double rdir=cross(b-a,c-a);
	if(rdir> EPS) return CCW;
	if(rdir<-EPS) return CW;
	return ON;
}

polygon convex_hull(vector<point> &P){
	int n=P.size();
	polygon CH;
	if(n<=1){
		CH.insert(CH.end(),P.begin(),P.end());
		return CH;
	}
	sort(P.begin(),P.end());

	rep(_,2){
		int m=0;
		vector<point> half(n);
		rep(i,n){
			half[m++]=P[i];
			while(m>=3 && ccw(half[m-3],half[m-2],half[m-1])!=CCW){
				half[m-2]=half[m-1];
				m--;
			}
		}
		CH.insert(CH.end(),half.begin(),half.begin()+m-1);
		reverse(P.begin(),P.end());
	}

	return CH;
}

int main(){
	int n; scanf("%d",&n);

	polygon G={point(0,0)};
	rep(i,n){
		point p; scanf("%lf%lf",&p.x,&p.y);

		vector<point> H=G;
		for(point q:G) H.emplace_back(q+p);
		G=convex_hull(H);
	}

	double ans=0;
	for(point p:G) ans=max(ans,abs(p));
	printf("%.10f\n",ans);

	return 0;
}
