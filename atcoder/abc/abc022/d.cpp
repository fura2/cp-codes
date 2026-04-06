#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;
const double PI=acos(-1);

struct point{
	double x,y;
	point():x(0),y(0){}
	point(double x,double y):x(x),y(y){}
	point& operator+=(const point& a){ x+=a.x; y+=a.y; return *this; }
	point& operator-=(const point& a){ x-=a.x; y-=a.y; return *this; }
	point operator+(const point& a)const{ return point(x+a.x,y+a.y); }
	point operator-(const point& a)const{ return point(x-a.x,y-a.y); }
	bool operator< (const point& a)const{ return x+EPS<a.x || (abs(x-a.x)<EPS && y+EPS<a.y); }
};

double cross(const point& a,const point& b){ return a.x*b.y-a.y*b.x; }

typedef vector<point> polygon;

double dist2(const point& a,const point& b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

enum{CCW=1,CW=-1,ON=0};
int ccw(const point& a,const point& b,const point& c){
	double rdir=cross(b-a,c-a);
	if(rdir> EPS) return CCW;
	if(rdir<-EPS) return CW;
	return ON;
}

polygon convex_hull(vector<point> P){
	int n=P.size();
	if(n<=1) return P;

	sort(P.begin(),P.end());

	polygon CH;
	rep(_,2){
		int m=0;
		vector<point> half(n);
		for(const point& p:P){
			half[m++]=p;
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

vector<pair<int,int>> antipodal_pairs(const polygon& G){
	int n=G.size(),i0=0,j0=0;
	rep(i,n){
		if(G[i].y>G[i0].y) i0=i;
		if(G[i].y<G[j0].y) j0=i;
	}

	vector<pair<int,int>> res;
	int i=i0,j=j0;
	do{
		if(cross(G[(i+1)%n]-G[i],G[(j+1)%n]-G[j])>=0) j=(j+1)%n;
		else                                          i=(i+1)%n;
		res.emplace_back(i,j);
	}while(i!=i0 || j!=j0);
	return res;
}

int main(){
	int n; scanf("%d",&n);
	polygon G(n),H(n);
	rep(i,n){
		double x,y; scanf("%lf%lf",&x,&y);
		G[i]={x,y};
	}
	rep(i,n){
		double x,y; scanf("%lf%lf",&x,&y);
		H[i]={x,y};
	}

	G=convex_hull(G);
	H=convex_hull(H);

	auto diam=[](const polygon& G){
		double res=0;
		for(auto I:antipodal_pairs(G)){
			res=max(res,dist2(G[I.first],G[I.second]));
		}
		return sqrt(res);
	};

	printf("%.9f\n",diam(H)/diam(G));

	return 0;
}
