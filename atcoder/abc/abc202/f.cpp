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

Real cross(const point& p,const point& q){ return p.x*q.y-p.y*q.x; }

Real arg(const point& v){ Real t=atan2(v.y,v.x); return t<0?t+2*PI:t; }

enum{CCW=1,CW=-1,ON=0};
int ccw(const point& a,const point& b,const point& c){
	int d=sgn(cross(b-a,c-a));
	return d>0?CCW:d<0?CW:ON;
}

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=(long long)x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return -x; }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=t; return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

int area2(const point &a,const point &b,const point &c){
	return abs(cross(b-a,c-a));
}

int n;
vector<point> P;

bool vis[80][80][2];
mint memo[80][80][2];

mint dfs(point p0,int i,int j,int par){
	if(j==P.size()){
		return par==0?1:0;
	}

	mint& res=memo[i][j][par];
	if(vis[i][j][par]) return res;
	vis[i][j][par]=true;

	res=0;
	for(int k=j+1;k<=P.size();k++){
		point q=(k<P.size()?P[k]:p0);
		if(ccw(P[i],P[j],q)==CCW){
			mint two=1;
			for(int l=j+1;l<k;l++) if(ccw(P[j],P[l],q)==CW) two*=2;
			res+=dfs(p0,j,k,(par+area2(p0,P[j],q))%2)*two;
		}
	}
	return res;
}

int main(){
	scanf("%d",&n);
	vector<point> Q(n);
	rep(i,n) scanf("%lf%lf",&Q[i].x,&Q[i].y);

	mint ans=0;
	rep(i,n) rep(j,n) {
		if(make_pair(Q[i].y,Q[i].x)>=make_pair(Q[j].y,Q[j].x)) continue;

		P.clear();
		rep(k,n){
			if(k==j || (ccw(Q[i],Q[j],Q[k])==CCW && Q[k].y>Q[i].y)){
				P.emplace_back(Q[k]);
			}
		}
		sort(P.begin(),P.end(),[&](point p1,point p2){
			double t1=arg(p1-Q[i]);
			double t2=arg(p2-Q[i]);
			double t0=arg(Q[j]-Q[i]);
			if(t1+EPS<t0) t1+=2*PI;
			if(t2+EPS<t0) t2+=2*PI;
			return t1+EPS<t2;
		});

		memset(vis,0,sizeof vis);
		for(int k=1;k<P.size();k++){
			mint two=1;
			for(int l=1;l<k;l++) if(ccw(Q[j],P[l],P[k])==CW) two*=2;
			ans+=dfs(Q[i],0,k,area2(Q[i],Q[j],P[k])%2)*two;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
