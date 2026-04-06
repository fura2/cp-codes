#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

template<class T>
vector<T> longest_increasing_subsequence(const vector<T> &a){
	vector<T> lis;
	for(const auto& x:a){
		auto it=lower_bound(lis.begin(),lis.end(),x);
		if(it!=lis.end()) *it=x;
		else lis.emplace_back(x);
	}
	return lis;
}

int main(){
	int sx,sy,gx,gy,n;
	scanf("%d%d%d%d%d",&sx,&sy,&gx,&gy,&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	if(sx>gx){
		sx*=-1;
		gx*=-1;
		rep(i,n) x[i]*=-1;
	}
	if(sy>gy){
		sy*=-1;
		gy*=-1;
		rep(i,n) y[i]*=-1;
	}

	vector<int> Y;
	{
		vector<pair<int,int>> p;
		rep(i,n) if(sx<=x[i] && x[i]<=gx && sy<=y[i] && y[i]<=gy) {
			p.emplace_back(x[i],y[i]);
		}
		sort(p.begin(),p.end(),[](const auto& a,const auto& b){
			return make_pair(a.first,-a.second)<make_pair(b.first,-b.second);
		});
		rep(i,p.size()) Y.emplace_back(p[i].second);
	}

	int m=longest_increasing_subsequence(Y).size();
	if(m<=min(gx-sx,gy-sy)) printf("%.15f\n",100.0*(gx-sx+gy-sy)+(5*PI-20)*m);
	else                    printf("%.15f\n",100.0*(gx-sx+gy-sy)+(5*PI-20)*(m-1)+(10*PI-20));

	return 0;
}
