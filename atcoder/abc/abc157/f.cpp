#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using Real=double;

constexpr Real EPS=1e-8;
constexpr Real PI=acos(Real(-1));

int sgn(const Real& x){ return x>EPS?1:x<-EPS?-1:0; }

class point{
public:
	Real x,y;
	point(){}
	point(const Real& x,const Real& y):x(x),y(y){}
	point& operator+=(const point& p){ x+=p.x; y+=p.y; return *this; }
	point& operator-=(const point& p){ x-=p.x; y-=p.y; return *this; }
	point& operator*=(const Real& c){ x*=c; y*=c; return *this; }
	point& operator/=(const Real& c){ x/=c; y/=c; return *this; }
	point operator+(const point& p)const{ return point(*this)+=p; }
	point operator-(const point& p)const{ return point(*this)-=p; }
	point operator*(const Real& c)const{ return point(*this)*=c; }
	point operator/(const Real& c)const{ return point(*this)/=c; }
	point operator-()const{ return point(-x,-y); }
	bool operator==(const point& p)const{ return sgn(x-p.x)==0 && sgn(y-p.y)==0; }
	bool operator!=(const point& p)const{ return !((*this)==p); }

	friend point operator*(const Real& c,const point& p){ return p*c; }
};

Real dot  (const point& p,const point& q){ return p.x*q.x+p.y*q.y; }
Real cross(const point& p,const point& q){ return p.x*q.y-p.y*q.x; }

Real abs (const point& p){ return sqrt(p.x*p.x+p.y*p.y); }

class circle{
public:
	point c;
	Real r;
	circle(){}
	circle(const point& c,const Real& r):c(c),r(r){}
};

bool cover(const circle& C,const point& p){
	return sgn(abs(C.c-p)-C.r)<=0;
}

vector<point> get_intersect(const circle& C1,const circle& C2){
	const point& p1=C1.c;
	const point& p2=C2.c;
	const Real& r1=C1.r;
	const Real& r2=C2.r;

	vector<point> res;
	if(p1==p2 && sgn(r1-r2)==0) return res;

	Real d=abs(p1-p2);
	if(sgn((r1+r2)-d)>=0 && sgn(d-abs(r1-r2))>=0){
		Real a=(r1*r1-r2*r2+d*d)/(2*d);
		Real h=sqrt(max(r1*r1-a*a,Real(0)));
		point tmp1=p1+a/d*(p2-p1);
		point tmp2=h/d*(p2-p1);
		if(sgn(abs(tmp2))==0){
			res.emplace_back(tmp1);
		}
		else{
			res.emplace_back(tmp1.x-tmp2.y,tmp1.y+tmp2.x);
			res.emplace_back(tmp1.x+tmp2.y,tmp1.y-tmp2.x);
		}
	}
	return res;
}

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<point> P(n);
	vector<double> cost(n);
	rep(i,n) cin>>P[i].x>>P[i].y>>cost[i];

	double lo=0,hi=1e9;
	rep(_,60){
		double mi=(lo+hi)/2;

		vector<point> C=P;
		rep(i,n) rep(j,i) {
			for(auto p:get_intersect(circle(P[i],mi/cost[i]),circle(P[j],mi/cost[j]))){
				C.emplace_back(p);
			}
		}

		bool ok=false;
		for(point p:C){
			int cnt=0;
			rep(i,n) if(cover(circle(p,mi/cost[i]),P[i])) cnt++;
			if(cnt>=k){ ok=true; break; }
		}
		if(ok) hi=mi;
		else   lo=mi;
	}
	printf("%.9f\n",lo);

	return 0;
}
