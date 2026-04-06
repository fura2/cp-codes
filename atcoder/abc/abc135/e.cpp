#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

struct point{
	lint x,y;
	point(lint x,lint y):x(x),y(y){}
};

vector<point> solve(lint X,lint Y,lint k){
	if(X<0){
		auto res=solve(-X,Y,k);
		for(auto& p:res) p.x*=-1;
		return res;
	}

	if(Y<0){
		auto res=solve(X,-Y,k);
		for(auto& p:res) p.y*=-1;
		return res;
	}

	if(X>Y){
		auto res=solve(Y,X,k);
		for(auto& p:res) swap(p.x,p.y);
		return res;
	}

	// 0 <= X <= Y
	vector<point> res;
	if(X+Y<k && (X+Y)%2==1){ // corner case (3 回曲がる)
		assert(k%2==1);
		lint x=0,y=0,dx,dy;
		lint a=(3*k-(X+Y))/2;
		lint a1=a/2,a2=(a+1)/2; // a1 + a2 == a
		dx=k-a1;
		dy=-a1;
		x+=dx; y+=dy; res.emplace_back(x,y);
		dx=(X+a2)-x;
		dy=k-dx;
		x+=dx; y+=dy; res.emplace_back(x,y);
		dx=-a2;
		dy=Y-y;
		x+=dx; y+=dy; res.emplace_back(x,y);
	}
	else if((X+Y)%k==0){ // 無駄なし (0 or 1 回曲がる)
		lint x=0,y=0;
		while((X-x)+(Y-y)>0){
			lint dx=min(k,X-x);
			lint dy=k-dx;
			x+=dx; y+=dy; res.emplace_back(x,y);
		}
	}
	else{ // 2 回曲がる
		lint x=0,y=0,dx,dy;
		while((X-x)+(Y-y)>2*k || ((X-x)+(Y-y))%2==1){
			lint dx=min(k,X-x);
			lint dy=k-dx;
			x+=dx; y+=dy; res.emplace_back(x,y);
		}
		// (X-x)+(Y-y) < 2*k and X-x <= Y-y and (X-x)+(Y-y) == 0 (mod 2)

		// あと 2 回でゴール
		lint a=(2*k-(X-x)-(Y-y))/2;
		dx=(X-x)+a;
		dy=k-dx;
		x+=dx; y+=dy; res.emplace_back(x,y);
		dx=-a;
		dy=Y-y;
		x+=dx; y+=dy; res.emplace_back(x,y);
	}
	return res;
}

int main(){
	lint k,X,Y; scanf("%lld%lld%lld",&k,&X,&Y);

	if(k%2==0 && (X+Y)%2!=0){
		cout<<-1<<'\n';
		return 0;
	}

	auto res=solve(X,Y,k);

	printf("%lu\n",res.size());
	for(auto& p:res) printf("%lld %lld\n",p.x,p.y);

	return 0;
}
