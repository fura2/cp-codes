#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;

struct point3{
	double x,y,z;
	point3 operator+(const point3& p)const{ return {x+p.x,y+p.y,z+p.z}; }
	point3 operator-(const point3& p)const{ return {x-p.x,y-p.y,z-p.z}; }
};
point3 operator*(double c,const point3& p){ return {c*p.x,c*p.y,c*p.z}; }

double dot(const point3& p,const point3& q){
	return p.x*q.x+p.y*q.y+p.z*q.z;
}

point3 cross(const point3& p,const point3& q){
	return {p.y*q.z-q.y*p.z,p.z*q.x-q.z*p.x,p.x*q.y-q.x*p.y};
}

double abs(const point3& p){
	return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}

double abs2(const point3& p){
	return p.x*p.x+p.y*p.y+p.z*p.z;
}

struct line3{
	point3 a,b;
	line3(const point3& a,const point3& b):a(a),b(b){}
};

int main(){
	int n; cin>>n;
	vector<point3> P(n);
	for(auto& p:P) cin>>p.x>>p.y>>p.z;
	sort(P.begin(),P.end(),[](auto& p,auto& q){ return p.x<q.x; });

	vector<line3> L;
	rep(i,n) for(int j=i+1;j<n;j++) {
		bool dup=false;
		for(auto l:L) if(abs2(cross(P[j]-P[i],l.b-l.a))<EPS && abs2(cross(l.a-P[i],l.b-l.a))<EPS) dup=true;
		if(!dup) L.emplace_back(P[i],P[j]);
	}
	int m=L.size();

	vector<point3> Q;
	rep(i,m){
		point3 p1=L[i].a,v1=L[i].b-L[i].a;
		if(v1.x!=0){
			point3 q=p1+((-p1.x-1)/v1.x)*v1;
			bool dup=false;
			for(auto& r:Q) if(abs2(q-r)<EPS) dup=true;
			if(!dup) Q.emplace_back(q);
		}
		for(int j=i+1;j<m;j++){
			point3 p2=L[j].a,v2=L[j].b-L[j].a;
			point3 u=cross(v1,v2);
			if(abs2(u)>EPS && abs(dot(u,p1-p2))<EPS){
				double s=dot(u,cross(v2,p1-p2))/dot(u,u);
				point3 q=p1+s*v1;
				if(q.x<-EPS){
					bool dup=false;
					for(auto& r:Q) if(abs2(q-r)<EPS) dup=true;
					if(!dup) Q.emplace_back(q);
				}
			}
		}
	}

	int ans=n;
	for(auto q:Q){
		int cnt=0;
		rep(i,n){
			bool visible=true;
			rep(j,i){
				if(abs2(cross(P[i]-q,P[j]-q))<EPS){
					visible=false;
					break;
				}
			}
			if(visible) cnt++;
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<'\n';

	return 0;
}
