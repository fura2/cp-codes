#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class G>
class Fenwick_tree_dual{
	vector<G> a;
public:
	Fenwick_tree_dual(int n=0){ build(n); }
	Fenwick_tree_dual(const vector<G>& a){ build(a); }
	void build(int n){
		a.assign(n,G{});
	}
	void build(const vector<G>& a){
		this->a=a;
		for(int i=1;i<=a.size();i++) if(i+(i&-i)<=a.size()) (this->a)[i-1]-=(this->a)[i+(i&-i)-1];
	}
	void add(int l,int r,const G& val){
		if(l==0){
			for(;r>0;r-=r&-r) a[r-1]+=val;
			return;
		}
		add(0,r,val);
		add(0,l,-val);
	}
	G get(int i)const{
		G res{};
		for(i++;i<=a.size();i+=i&-i) res+=a[i-1];
		return res;
	}
};

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
Real abs2(const point& p){ return p.x*p.x+p.y*p.y; }

point rot(const point& p,const Real& theta){
	return {p.x*cos(theta)-p.y*sin(theta),p.x*sin(theta)+p.y*cos(theta)};
}

Real angle(const point& v){ Real t=atan2(v.y,v.x); return t<0?t+2*PI:t; }

class line{
public:
	point a,b;
	line(){}
	line(const point& a,const point& b):a(a),b(b){}
	bool operator==(const line& L)const{
		return sgn(cross(b-a,L.b-L.a))==0 && sgn(cross(L.a-a,L.b-a))==0;
	}
	bool operator!=(const line& L)const{ return !((*this)==L); }
};

class segment{
public:
	point a,b;
	segment(){}
	segment(const point& a,const point& b):a(a),b(b){}
	operator line()const{ return line(a,b); }
};

using polygon=vector<point>;

class circle{
public:
	point c;
	Real r;
	circle(){}
	circle(const point& c,const Real& r):c(c),r(r){}
};

point proj(const point& p,const line& L){ return L.a+dot(p-L.a,L.b-L.a)/abs2(L.b-L.a)*(L.b-L.a); }

bool is_ccw(const polygon &F){
	int n=F.size();
	double A=0;
	rep(i,n) A+=cross(F[i],F[(i+1)%n]);
	return A>-EPS;
}

int main(){
	enum{SEGMENT,QUERY};
	vector<tuple<double,int,int,int,int>> Ev; // (x, y1, y2, type, in/out or query id)
	int n; scanf("%d",&n);
	rep(i,n){
		int m; scanf("%d",&m);
		polygon F(m);
		rep(j,m) scanf("%lf%lf",&F[j].x,&F[j].y);
		if(!is_ccw(F)) reverse(F.begin(),F.end());
		rep(j,m){
			if(F[j].x==F[(j+1)%m].x){
				if(F[j].y<F[(j+1)%m].y){
					Ev.emplace_back(F[j].x,F[j].y,F[(j+1)%m].y,SEGMENT,-1);
				}
				else{
					Ev.emplace_back(F[j].x,F[(j+1)%m].y,F[j].y,SEGMENT,1);
				}
			}
		}
	}

	int q; scanf("%d",&q);
	rep(i,q){
		int x,y; scanf("%d%d",&x,&y);
		Ev.emplace_back(x+0.5,y,y,QUERY,i);
	}

	sort(Ev.begin(),Ev.end());

	vector<int> ans(q);
	Fenwick_tree_dual<int> F(1e5+1);
	for(auto [x,y1,y2,type,io]:Ev){
		if(type==SEGMENT){
			F.add(y1,y2,io);
		}
		else{ // QUERY
			ans[io]=F.get(y1);
		}
	}

	rep(i,q) printf("%d\n",ans[i]);

	return 0;
}
