#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;
const double INF=1e9;
const double PI=acos(-1);

struct point{
	double x,y;
	point():x(0),y(0){}
	point(double x,double y):x(x),y(y){}
	point operator+(const point &a)const{ return point(x+a.x,y+a.y); }
	point operator-(const point &a)const{ return point(x-a.x,y-a.y); }
	point operator/(double c)const{ return point(x/c,y/c); }
	bool operator==(const point &a)const{ return abs(x-a.x)<EPS && abs(y-a.y)<EPS; }
};

point operator*(double c,const point &a){ return point(c*a.x,c*a.y); }

double cross(const point &a,const point &b){ return a.x*b.y-a.y*b.x; }

double abs(const point &a){ return sqrt(a.x*a.x+a.y*a.y); }

struct line{
	point a,b;
	line(){}
	line(const point &a,const point &b):a(a),b(b){}
	bool operator==(const line &L)const{ return abs(cross(b-a,L.b-L.a))<EPS && abs(cross(L.a-a,L.b-a))<EPS; }
};

double dist2(const point &a,const point &b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double dist(const line &L,const point &p){
	return abs(cross(L.b-L.a,p-L.a))/abs(L.a-L.b);
}

bool intersect(const line &L1,const line &L2){
	return abs(cross(L1.b-L1.a,L2.b-L2.a))>EPS
		|| abs(cross(L1.b-L1.a,L2.a-L1.a))<EPS;
}

point get_intersect(const line &L1,const line &L2){
	double a1=cross(L1.b-L1.a,L2.b-L2.a);
	double a2=cross(L1.b-L1.a,L1.b-L2.a);
	if(abs(a1)<EPS) return L1.a;
	return L2.a+a2/a1*(L2.b-L2.a);
}

line perp_bisector(const point &a,const point &b){
	return line(point((a.x-a.y+b.x+b.y)/2.0,(a.y+a.x+b.y-b.x)/2.0),
				point((a.x+a.y+b.x-b.y)/2.0,(a.y-a.x+b.y+b.x)/2.0));
}

line angle_bisector(const line &L,const line &M){
	point c=get_intersect(L,M);
	point u=L.b-L.a,v=M.b-M.a;
	return line(c,c+u/abs(u)+v/abs(v));
}

line abc_to_line(double a,double b,double c){
	line L;
	if(abs(b)<abs(a)){
		L.a=point(-b/a-c/a, 1);
		L.b=point( b/a-c/a,-1);
	}
	else{
		L.a=point( 1,-a/b-c/b);
		L.b=point(-1, a/b-c/b);
	}
	return L;
}

int main(){
	int n,m;
	double R; cin>>n>>m>>R;
	line L[16];
	rep(i,n){
		double a,b,c; cin>>a>>b>>c;
		L[i]=abc_to_line(a,b,c);
		bool dup=false;
		rep(j,i) if(L[i]==L[j]) dup=true;
		if(dup) n--, i--;
	}
	point P[16];
	rep(i,m){
		double x,y; cin>>x>>y;
		P[i]={x,y};
		bool dup=false;
		rep(j,i) if(P[i]==P[j]) dup=true;
		if(dup) m--, i--;
	}

	vector<line> Cand; // candidates
	rep(j,n) rep(i,j) if(intersect(L[i],L[j])) {
		rep(_,2){
			Cand.emplace_back(angle_bisector(L[i],L[j]));
			swap(L[j].a,L[j].b);
		}
	}
	rep(j,m) rep(i,j) {
		Cand.emplace_back(perp_bisector(P[i],P[j]));
	}
	Cand.push_back({{-R,-R},{ R,-R}});
	Cand.push_back({{-R, R},{ R, R}});
	Cand.push_back({{-R,-R},{-R, R}});
	Cand.push_back({{ R,-R},{ R, R}});

	double ans=0;
	rep(j,Cand.size()) rep(i,j) if(intersect(Cand[i],Cand[j])) {
		point p=get_intersect(Cand[i],Cand[j]);
		if(-R-EPS<p.x && p.x<R+EPS && -R-EPS<p.y && p.y<R+EPS){
			double d1=INF;
			rep(k,n) d1=min(d1,dist(L[k],p));
			double d2=INF;
			rep(k,m) d2=min(d2,dist2(P[k],p));
			ans=max(ans,d1+d2);
		}
	}
	cout<<setprecision(9)<<ans<<endl;

	return 0;
}
