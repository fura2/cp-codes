#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using Real=int;

constexpr Real EPS=0;

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

int main(){
	int n; scanf("%d",&n);
	vector<point> P1(n),P2(n);
	rep(i,n) scanf("%d%d",&P1[i].x,&P1[i].y);
	rep(i,n) scanf("%d%d",&P2[i].x,&P2[i].y);

	if(n==1){
		puts("Yes");
		return 0;
	}

	vector<pair<int,int>> IO1(n);
	rep(i,n){
		IO1[i]={
			dot(P1[i]-P1[0],P1[1]-P1[0]),
			cross(P1[i]-P1[0],P1[1]-P1[0])
		};
	}
	sort(IO1.begin(),IO1.end());

	rep(i,n) rep(j,n) if(i!=j) {
		vector<pair<int,int>> IO2(n);
		rep(k,n){
			IO2[k]={
				dot(P2[k]-P2[i],P2[j]-P2[i]),
				cross(P2[k]-P2[i],P2[j]-P2[i])
			};
		}
		sort(IO2.begin(),IO2.end());
		if(IO1==IO2){
			puts("Yes");
			return 0;
		}
	}
	puts("No");

	return 0;
}
