#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class Real{
	using T=long double;
	constexpr static T EPS=1e-10;
	T x;
public:
	Real(const T& x=0):x(x){}
	Real& operator+=(const Real& r){ x+=r.x; return *this; }
	Real& operator-=(const Real& r){ x-=r.x; return *this; }
	Real& operator*=(const Real& r){ x*=r.x; return *this; }
	Real& operator/=(const Real& r){ x/=r.x; return *this; }
	Real operator+(const Real& r)const{ return Real(*this)+=r; }
	Real operator-(const Real& r)const{ return Real(*this)-=r; }
	Real operator*(const Real& r)const{ return Real(*this)*=r; }
	Real operator/(const Real& r)const{ return Real(*this)/=r; }
	Real operator-()const{ return Real(-x); }
	bool operator< (const Real& r)const{ return x<r.x-EPS; }
	bool operator> (const Real& r)const{ return r<(*this); }
	bool operator<=(const Real& r)const{ return !(r<(*this)); }
	bool operator>=(const Real& r)const{ return !((*this)<r); }
	bool operator==(const Real& r)const{ return !((*this)<r) && !(r<(*this)); }
	bool operator!=(const Real& r)const{ return (*this)<r || r<(*this); }

	friend Real operator+(const T& x,const Real& r){ return Real(x)+r; }
	friend Real operator-(const T& x,const Real& r){ return Real(x)-r; }
	friend Real operator*(const T& x,const Real& r){ return Real(x)*r; }
	friend Real operator/(const T& x,const Real& r){ return Real(x)/r; }

	friend istream& operator>>(istream& is,Real& r){ T s; is>>s; r=Real(s); return is; }
	friend ostream& operator<<(ostream& os,const Real& r){ return os<<r.x; }

	friend Real abs  (const Real& r){ return abs(r.x); }
	friend Real sqrt (const Real& r){ return sqrt(r.x); }
	friend Real cos  (const Real& r){ return cos(r.x); }
	friend Real sin  (const Real& r){ return sin(r.x); }
	friend Real atan2(const Real& y,const Real& x){ return atan2(y.x,x.x); }
};

const Real PI=acos(-1.0L);

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
	bool operator< (const point& p)const{ return tie(x,y)<tie(p.x,p.y); }
	bool operator==(const point& p)const{ return x==p.x && y==p.y; }
	bool operator!=(const point& p)const{ return !((*this)==p); }

	friend point operator*(const Real& c,const point& p){ return p*c; }
};

Real dot  (const point& p,const point& q){ return p.x*q.x+p.y*q.y; }
Real cross(const point& p,const point& q){ return p.x*q.y-p.y*q.x; }

Real abs (const point& p){ return sqrt(p.x*p.x+p.y*p.y); }
Real abs2(const point& p){ return p.x*p.x+p.y*p.y; }

class line{
public:
	point a,b;
	line(){}
	line(const point& a,const point& b):a(a),b(b){}
	bool operator==(const line& L)const{ return cross(b-a,L.b-L.a)==0 && cross(L.a-a,L.b-a)==0; }
};

class segment{
public:
	point a,b;
	segment(){}
	segment(const point& a,const point& b):a(a),b(b){}
	operator line()const{ return line(a,b); }
};

Real dist(const point& a,const point& b){ return abs(a-b); }

Real dist(const segment &S,const point &p){
	if(dot(S.b-S.a,p-S.a)<=0) return dist(p,S.a);
	if(dot(S.a-S.b,p-S.b)<=0) return dist(p,S.b);
	return abs(cross(S.b-S.a,p-S.a))/dist(S.a,S.b);
}

const double INF=1e77;

int main(){
	point p;
	int n; cin>>p.x>>p.y>>n;
	vector<point> Q(n);
	rep(i,n) cin>>Q[i].x>>Q[i].y;

	Real ans=INF;
	rep(i,n) ans=min(ans,dist(segment(Q[i],Q[(i+1)%n]),p));
	cout<<setprecision(9)<<ans<<'\n';

	return 0;
}
