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

point rot(const point& p,const Real& theta){
	return {p.x*cos(theta)-p.y*sin(theta),p.x*sin(theta)+p.y*cos(theta)};
}

Real arg(const point& v){ Real t=atan2(v.y,v.x); return t<0?t+2*PI:t; }

enum{CCW=1,CW=-1,ON=0};
int ccw(const point& a,const point& b,const point& c){
	auto rdir=cross(b-a,c-a);
	return rdir>0?CCW:rdir<0?CW:ON;
}

using polygon=vector<point>;

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
			while(m>=3 && ccw(half[m-3],half[m-2],half[m-1])==CW){
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
	vector<point> P(n);
	rep(i,n) cin>>P[i].x>>P[i].y;

	auto CH=convex_hull(P);
	int m=CH.size();
	vector<Real> theta(m);
	rep(i,m){
		theta[i]=arg(rot(CH[(i+1)%m]-CH[i],-PI/2));
		if(i>0 && theta[i]<theta[i-1]) theta[i]+=2*PI;
	}

	map<point,Real> f;
	f[CH[0]]=(theta[0]+2*PI)-theta[m-1];
	rep(i,m-1) f[CH[i+1]]=theta[i+1]-theta[i];

	rep(i,n){
		if(f.count(P[i])==0){
			puts("0");
		}
		else{
			cout<<setprecision(15)<<f[P[i]]/(2*PI)<<'\n';
		}
	}
	return 0;
}
