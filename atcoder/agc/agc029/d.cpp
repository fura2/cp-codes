#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	vector<pair<int,int>> p(n);
	rep(i,n){
		int y,x; scanf("%d%d",&y,&x); y--; x--;
		p[i]={y,x};
	}

	sort(p.begin(),p.end());

	vector Y(w,vector<int>());
	for(auto [y,x]:p) Y[x].emplace_back(y);
	rep(x,w) Y[x].emplace_back(h);

	int ans=h,y=0,x=0;
	while(1){
		ans=min(ans,*upper_bound(Y[x].begin(),Y[x].end(),y));
		if(y==h-1 || binary_search(p.begin(),p.end(),make_pair(y+1,x))){
			break;
		}
		y++;
		if(x<w-1 && !binary_search(p.begin(),p.end(),make_pair(y,x+1))){
			x++;
		}
	}
	printf("%d\n",ans);

	return 0;
}
