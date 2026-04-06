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

	friend Real operator*(const T& c,const Real& r){ return r*c; }

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

class circle{
public:
	point c;
	Real r;
	circle(){}
	circle(const point& c,const Real& r):c(c),r(r){}
};

bool cover(const circle &C,const point &p){
	return abs(C.c-p)<=C.r;
}

class smallest_enclosing_circle{
	random_device seed_gen;
	mt19937 rng;

	vector<point> P;
	vector<int> bdry;

	circle make_circle(){
		int m=bdry.size();
		if(m==0) return circle(point(0,0),-1);

		// (c, sqrt(r2)) := ({bdry[0], ..., bdry[i]} の最小包含円)
		point c=P[bdry[0]],v[2];
		Real r2=0,z[2];
		rep(i,m-1){
			point delta=P[bdry[i+1]]-c;

			// Gram-Schmidt
			v[i]=delta;
			rep(j,i) v[i]-=dot(v[j],delta)/z[j]*v[j];
			z[i]=abs2(v[i]);

			Real a=abs2(delta)-r2;
			c+=a/(2*z[i])*v[i];
			r2+=a*a/(4*z[i]);
		}

		return circle(c,sqrt(r2));
	}

	circle dfs(int i){
		if(i==P.size() || bdry.size()==3) return make_circle();

		circle C=dfs(i+1);
		if(C.r!=-1 && cover(C,P[i])) return C;

		bdry.emplace_back(i);
		C=dfs(i+1);
		bdry.pop_back();
		return C;
	}

public:
	smallest_enclosing_circle(const vector<point>& P):rng(seed_gen()),P(P){}
	circle find(){
		bdry.clear();
		shuffle(P.begin(),P.end(),rng);
		return dfs(0);
	}
};

int main(){
	int n; cin>>n;
	vector<point> P(n);
	rep(i,n) cin>>P[i].x>>P[i].y;
	cout<<setprecision(9)<<smallest_enclosing_circle(P).find().r<<'\n';
	return 0;
}
